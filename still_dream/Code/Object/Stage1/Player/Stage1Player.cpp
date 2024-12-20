#include"Stage1Player.h"

namespace dream
{
    Stage1Player::Stage1Player()
        :GameObject(stage1ObjectTag.PLAYER)
    {
        mPos.x = 200;
        mPos.y = 800;
        jumpFlag = false;
        prevJumpButton = false;
        isJumpPush = false;
        onGround = false;

        PlayerHandle = LoadGraph("Asset/Image/Character.png");
    }

    Stage1Player::~Stage1Player()
    {
        DeleteGraph(PlayerHandle);
    }

    void Stage1Player::Update(float deltaTime)
    {
        Draw();
    }

    void Stage1Player::Draw()
    {
        DrawGraph(mPos.x, mPos.y, PlayerHandle, TRUE);
    }

    void Stage1Player::Input()
    {
        if (onGround)   //接地してるとき
        {
            jumpFlag = false;
            vy = 0.0f;
        }
        else
        {
            jumpFlag = true;
        }

        //ジャンプボタン押した瞬間か
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            if (!prevJumpButton)
            {
                isJumpPush = true;
            }
            else
            {
                isJumpPush = false;
            }
            prevJumpButton = true;
        }
        else
        {
            prevJumpButton = false;
        }

        //ジャンプ可能でジャンプキーが押された
        if (isJumpPush && !jumpFlag)
        {
            vy -= jumpInitVelocity;
            jumpFlag = true;
            onGround = false;
        }
    }
}