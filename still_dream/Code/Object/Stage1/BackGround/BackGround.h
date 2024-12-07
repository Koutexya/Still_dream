#pragma once
#include<DxLib.h>

#include"../../GameObject/GameObject.h"

namespace dream
{
    class BackGround : public GameObject
    {
    public:
        /// @brief  デストラクタ
        ~BackGround();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

    private:
        /// @brief  コンストラクタ
        BackGround();

        int BackGroundImg;
    };
}