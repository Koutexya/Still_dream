#pragma once
#include "../Collision/Collision.h"

namespace dream
{
    class ScrollManager
    {
    public:
        ScrollManager() {}

        ~ScrollManager() {}

        /// <summary>
        /// スクロールマネージャ初期化
        /// </summary>
        /// <param name="windowWidth">ウィンドウの幅ドット数</param>
        /// <param name="windowHeight">ウィンドウの高さドット数</param>
        /// <param name="worldRect">ステージ全体の矩形</param>
        void ScrollManagerInit(int screenWidth, int screenHeight, const Collision::sHitRect& worldRect);

        /// <summary>
        /// スクロールの更新処理
        /// </summary>
        /// <param name="playerRect">スクロールの中心となるキャラクター矩形</param>
        /// <param name="deltaTime">ウィンドウ更新時間</param>
        void ScrollUpdate(const Collision::sHitRect& playerRect, float deltaTime);

        /// <summary>
        /// スクロールの描画オフセットXを取得
        /// </summary>
        /// <returns>x方向オフセット</returns>
        int ScrollGetDrawOffsetX();

        /// <summary>
        /// スクロールの描画オフセットYを取得
        /// </summary>
        /// <returns>y方向オフセット</returns>
        int ScrollGetDrawOffsetY();

        /// <summary>
        /// スクロールのデバッグ情報表示
        /// </summary>
        void ScrollDebugShow();

        /// <summary>
        /// プレイ画面の領域矩形を取得
        /// </summary>
        /// <returns>プレイ画面のワールド座標矩形</returns>
        Collision::sHitRect GetPlayArea();

    private:
        float scrollX;      // スクロールX方向値
        float scrollY;      // スクロールY方向値

        float screenXMax;   // スクリーン上の右スクロール開始境界値
        float screenYMin;   // スクリーン上の上スクロール開始境界値
        float screenYMax;   // スクリーン上の下スクロール開始境界値

        int screenWidth;    // スクリーン幅
        int screenHeight;   // スクリーン高さ

        float scrollXMax;   // 最大横方向スクロール量
        float scrollYMin;   // 最小上方向スクロール量
        float scrollYMax;   // 最大下方向スクロール量

        float dx;
        float dy;

        const float scrollSpeed = 5.0f;
    };
}