#include"Stage1Player.h"

namespace dream
{
    Stage1Player::Stage1Player()
        :GameObject(stage1ObjectTag.PLAYER)
    {
        mPos.x = 200;
        mPos.y = 600;
        vx = 0.0f;
        vy = 0.0f;
        jumpFlag = false;
        prevJumpButton = false;
        isJumpPush = false;
        onGround = false;
        hitHead = false;

        Collision::initRect(playerHit, 100, 100);
        Collision::initRect(playerFootCollider, 90, 1);
        Collision::initRect(playerHeadCollider, 90, 1);

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

        Collision::updateWorldRect(playerHit, mPos.x, mPos.y);
        Collision::updateWorldRect(playerFootCollider, mPos.x, mPos.y + playerHit.h);
        Collision::updateWorldRect(playerHeadCollider, mPos.x, mPos.y);
    }

    void Stage1Player::Draw()
    {
        DrawGraph(mPos.x, mPos.y, PlayerHandle, TRUE);

        Collision::drawRect(playerHit);
        Collision::drawRect(playerFootCollider);
        Collision::drawRect(playerHeadCollider);
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

        

        //ジャンプ中重力発生
        if (jumpFlag)
        {
            vy += gravity * deltaTime;
        }

        
        //if(Stage1Map::mapHitCalc(playerHit))
        Stage1Map::MapLayer dat = stage1.getMapHitRect();
        if (Stage1Map::mapHitCalc(dat, playerHit))
        {
            playerfixColPosition(playerHit);
        }

        // 足元チェック
        //playerSetGroundFlg(Stage1Map::mapHitCalc(dat,playerFootCollider));


        //位置更新
        mPos.y += vy;

        
    }

    void Stage1Player::playerfixColPosition(Collision::sHitRect& hitRect)
    {
        //左右の壁に当たったので横方向速度を0に
        if (mPos.x != hitRect.worldLX)
        {
            vx = 0.0f;
        }
        //上下の壁に当たったので縦方向速度を0に
        if (mPos.y != hitRect.worldLY)
        {
            vy = 0.0f;
        }

        mPos.x = hitRect.worldLX;
        mPos.y = hitRect.worldLY;

        playerHit = hitRect;
    }

    Collision::sHitRect Stage1Player::getPlayerHitRect()
    {
        return playerHit;
    }

    void Stage1Player::playerSetGroundFlg(bool groundFlg)
    {
        onGround = groundFlg;
    }

    void Stage1Player::playerSetHeadHitFlg(bool headHitFlg)
    {
        hitHead = headHitFlg;
    }

    Collision::sHitRect Stage1Player::playerGetGroundCollider()
    {
        return playerFootCollider;
    }

    Collision::sHitRect Stage1Player::playerGetHeadCollider()
    {
        return playerHeadCollider;
    }


}