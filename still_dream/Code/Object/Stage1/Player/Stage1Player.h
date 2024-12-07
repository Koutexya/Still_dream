#pragma once
#include<DxLib.h>

#include"../../GameObject/GameObject.h"

namespace dream
{
    class Stage1Player : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Stage1Player();

        /// @brief  デストラクタ
        ~Stage1Player();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

        /// @brief  入力処理
        void Input()override;

    private:

    };
}