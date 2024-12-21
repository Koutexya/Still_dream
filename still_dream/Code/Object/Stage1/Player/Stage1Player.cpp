#include"Stage1Player.h"

namespace dream
{
    Stage1Player::Stage1Player()
        :GameObject(stage1ObjectTag.PLAYER)
    {
        mPos.x = 200;
        mPos.y = 800;
        vx = 0.0f;
        vy = 0.0f;
        jumpFlag = false;
        prevJumpButton = false;
        isJumpPush = false;
        onGround = false;
        jumpTimer = jumpButtonAcceptTime;

        PlayerHandle = LoadGraph("Asset/Image/Character.png");
    }

    Stage1Player::~Stage1Player()
    {
        DeleteGraph(PlayerHandle);
    }

    void Stage1Player::Update(float deltaTime)
    {
        Input(deltaTime);
        Draw();
    }

    void Stage1Player::Draw()
    {
        DrawGraph(mPos.x, mPos.y, PlayerHandle, TRUE);
    }

    void Stage1Player::Input(float deltaTime)
    {
        //当たり判定作ったら書き換え　この条件の時ジャンプ可能
        if (mPos.y == 800)
        {
            onGround = true;
        }

        if (onGround)   //接地してるとき
        {
            jumpFlag = false;
            vy = 0.0f;
            jumpTimer = jumpButtonAcceptTime;
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
        if (isJumpPush && !jumpFlag && jumpTimer>0.0f)
        {
            vy -= jumpInitVelocity;
            jumpFlag = true;
            onGround = false;
        }

        // ジャンプ長押し中で上昇タイマー期間なら上昇
        if (prevJumpButton && jumpTimer > 0.0f)
        {
            vy -= jumpUpSpeed * deltaTime;
        }

        //ジャンプ中重力発生
        if (jumpFlag)
        {
            jumpTimer -= deltaTime;
            vy += gravity * deltaTime;
        }

        //位置更新
        mPos.y += vy;
    }
}