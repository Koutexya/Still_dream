#include"Collision.h"

namespace dream
{

    Collision::Collision()
    {
    }

    Collision::~Collision()
    {

    }


    //当たり判定初期化
    void Collision::initRect(sHitRect& dstRect, float w, float h)
    {
        dstRect.w = w;
        dstRect.h = h;

        dstRect.worldLX = 0.0f;
        dstRect.worldRX = w;
        dstRect.worldLY = 0.0f;
        dstRect.worldRY = h;
    }

    //当たり判定の移動更新処理
    void Collision::updateWorldRect(sHitRect& dstRect, float x, float y)
    {
        dstRect.worldLX = x;
        dstRect.worldRX = x + dstRect.w;
        dstRect.worldLY = y;
        dstRect.worldRY = y + dstRect.h;
    }


    //当たり判定短形の描画
    void Collision::drawRect(const sHitRect& rect)
    {
        DrawBox(static_cast<int>(rect.worldLX),
            static_cast<int>(rect.worldLY),
            static_cast<int>(rect.worldRX - 1),
            static_cast<int>(rect.worldRY - 1),
            GetColor(255, 0, 0), FALSE);
    }

    //二つの矩形が衝突したかを返す
    bool Collision::isHitRect(const sHitRect& rect1, const sHitRect& rect2)
    {
        // 二つの矩形の当たり判定の公式より
        return (rect1.worldLX < rect2.worldRX&&
            rect2.worldLX < rect1.worldRX&&
            rect1.worldLY < rect2.worldRY&&
            rect2.worldLY < rect1.worldRY);
    }

    //2つの矩形の衝突めり込み量を計算
    void Collision::clacFixHitReactPosition(sHitRect& movableRect, const sHitRect& staticRect)
    {
       //押し戻し距離を計算
        float left = staticRect.worldLX - movableRect.worldRX;
        float right = staticRect.worldRX - movableRect.worldLX;
        float up = staticRect.worldLY - movableRect.worldRY;
        float down = staticRect.worldRY - movableRect.worldLY;
        

        //fabs() カッコ内に変数が絶対値を求める関数
        //dxはx方向の最短押し戻し移動量
        //dyはy方向の最短押し戻し移動量
        float dx = (fabs(left) < fabs(right)) ? left : right;
        float dy = (fabs(up) < fabs(down)) ? up : down;



        //x方向とy方向の最短押し戻し距離を比較し、最短で戻せる方で戻す
        if (fabs(dx) < fabs(dy))
        {
            movableRect.worldLX += dx;
            movableRect.worldRX += dx;
        }
        else
        {
            movableRect.worldLY += dy;
            movableRect.worldRY += dy;
        }
    }
}

