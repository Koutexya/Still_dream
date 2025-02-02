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
        firstmPos = false;
        scrollCnt = 0;

        Collision::initRect(playerHit, 100, 100);
        Collision::initRect(playerFootCollider, 100, 1);
        Collision::initRect(playerHeadCollider, 100, -1);
        Collision::initRect(playerRightCollider, 1, 70);

        // 当たり判定位置更新
        Collision::updateWorldRect(playerHit, static_cast<float>(mPos.x), static_cast<float>(mPos.y));
        Collision::updateWorldRect(playerFootCollider, static_cast<float>(mPos.x), static_cast<float>((mPos.y + playerHit.h)));
        Collision::updateWorldRect(playerHeadCollider, static_cast<float>(mPos.x), static_cast<float>(mPos.y));
        Collision::updateWorldRect(playerRightCollider, static_cast<float>((mPos.x + playerHit.w)), static_cast<float>((mPos.y + 10)));


        PlayerHandle = LoadGraph(JsonManager::StageDataInstance()->StageDataInstance()->GetCharaImg().c_str());
    }

    Stage1Player::~Stage1Player()
    {
        DeleteGraph(PlayerHandle);
    }

    void Stage1Player::Update(float deltaTime)
    {
        scrollCnt += 2;
        Input(deltaTime);

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
        if (Stage1Map::mapHitCalc(dat, playerHit, scrollCnt))
        {
            playerfixColPosition(playerHit);
        }

        // 足元チェック
        playerSetGroundFlg(Stage1Map::mapHitCalc(dat, playerFootCollider, scrollCnt));

        playerSetHeadHitFlg(Stage1Map::mapHitCalc(dat, playerHeadCollider, scrollCnt));

        //右側チェック
        if (Stage1Map::mapHitCalc(dat, playerRightCollider, scrollCnt))
        {
            StageSelect::SetGameFlag(stageTag.GameOver);
        }

        // 当たり判定位置更新
        Collision::updateWorldRect(playerHit, static_cast<float>(mPos.x), static_cast<float>(mPos.y));
        Collision::updateWorldRect(playerFootCollider, static_cast<float>(mPos.x), static_cast<float>((mPos.y + playerHit.h)));
        Collision::updateWorldRect(playerHeadCollider, static_cast<float>(mPos.x), static_cast<float>(mPos.y));
        Collision::updateWorldRect(playerRightCollider, static_cast<float>((mPos.x + playerHit.w)), static_cast<float>((mPos.y + 10)));
    }

    void Stage1Player::Draw()
    {
        DrawGraph(mPos.x, mPos.y, PlayerHandle, TRUE);

        Collision::drawRect(playerHit);
        Collision::drawRect(playerFootCollider);
        Collision::drawRect(playerHeadCollider);
        Collision::drawRect(playerRightCollider);
    }

    void Stage1Player::Input(float deltaTime)
    {
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

        //常に重力
        /*if (jumpFlag)
        {
            vy += gravity * deltaTime;
        }*/
        vy += gravity * deltaTime;
        



        //位置更新
        mPos.x += static_cast<LONG>(vx);
        mPos.y += static_cast<LONG>(vy);


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
            mPos.y = static_cast<LONG>(hitRect.worldLY);
        }
        else
        {
            mPos.x = static_cast<LONG>(hitRect.worldLX);
            mPos.y = static_cast<LONG>(hitRect.worldLY);
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