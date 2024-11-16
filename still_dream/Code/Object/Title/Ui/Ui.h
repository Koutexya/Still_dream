#pragma once
#include"../../GameObject/GameObject.h"

namespace dream
{
    class Ui : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Ui();

        /// @brief  デストラクタ
        ~Ui();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

    private:

    };
}