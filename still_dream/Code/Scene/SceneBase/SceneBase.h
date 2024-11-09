#pragma once
#include<DxLib.h>


namespace dream
{
    /// @brief  シーンの更新処理クラス
    class SceneBase
    {
    public:
        /// @brief  コンストラクタ
        SceneBase();

        /// @brief  デストラクタ
        ~SceneBase();

        /// @brief  シーン更新処理
        /// @param deltaTime=デルタタイム
        /// @return 次のフレームシーン
        virtual SceneBase* Update(const float deltaTime) = 0;

        /// @brief  シーン描画処理
        virtual void Draw() = 0;
    };
}