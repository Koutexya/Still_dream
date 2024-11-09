#pragma once
#include"../SceneBase/SceneBase.h"

namespace dream
{
    /// @brief  タイトル画面の進行管理クラス
    class Title :public SceneBase
    {
    public:
        /// @brief  コンストラクタ
        Title();

        /// @brief  デストラクタ
        ~Title();

        /// @brief  シーン更新処理
        /// @param deltaTime=デルタタイム
        /// @return 次のフレームシーン
        SceneBase* Update(const float deltaTime)override;

        /// @brief  シーン更新処理
        void Draw()override;
    };
}