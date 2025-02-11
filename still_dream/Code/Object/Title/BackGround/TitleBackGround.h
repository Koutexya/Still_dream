#pragma once
#include<DxLib.h>
#include"../../GameObject/GameObject.h"


namespace dream
{
    class TitleBackGround : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        TitleBackGround();

        /// @brief  デストラクタ
        ~TitleBackGround();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(const float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

    private:
        int BackGroundHandle;
    };
}