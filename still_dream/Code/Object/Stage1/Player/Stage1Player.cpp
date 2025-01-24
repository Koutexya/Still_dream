#include"Stage1Player.h"

namespace dream
{
    Stage1Player::Stage1Player()
        :GameObject(stage1ObjectTag.PLAYER)
    {
        mPos.x = 200;
        mPos.y = 300;
        vx = 0.0f;
        vy = 0.0f;
        jumpFlag = false;
        prevJumpButton = false;
        isJumpPush = false;
        onGround = false;
        hitHead = false;
        firstmPos = false;

        Collision::initRect(playerHit, 100, 100);
        Collision::initRect(playerFootCollider, 100, 1);
        Collision::initRect(playerHeadCollider, 100, 1);

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

        if (onGround)   //接地してるとき
        {
            jumpFlag = false;
            vy = 0.0f;
        }
        else
        {
            jumpFlag = true;
        }

        //player当たり判定チェック
        Stage1Map::MapLayer dat = stage1.getMapHitRect();
        if (Stage1Map::mapHitCalc(dat, playerHit))
        {
            playerfixColPosition(playerHit);
        }

        // 足元チェック
        playerSetGroundFlg(Stage1Map::mapHitCalc(dat, playerFootCollider));

        // 当たり判定位置更新
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
        if (CheckHitKey(KEY_INPUT_RIGHT))
        {
            vx += +2.5f * deltaTime;

            // 速度クリップ
            if (vx > 10.0f)
            {
                vx = +10.0f;
            }
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

        
        


        //位置更新
        mPos.x += vx;
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

        if (firstmPos != true)
        {
            mPos.y = hitRect.worldLY;
        }
        else
        {
            mPos.x = hitRect.worldLX;
            mPos.y = hitRect.worldLY;
        }
        firstmPos = false;

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