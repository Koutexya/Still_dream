#pragma once
#pragma once
#include"../SceneBase/SceneBase.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../Object/End/BackGround/EndBackGround.h"

namespace dream
{
    /// @brief  タイトル画面の進行管理クラス
    class End :public SceneBase
    {
    public:
        /// @brief  コンストラクタ
        End();

        /// @brief  デストラクタ
        ~End();

        /// @brief  シーン更新処理
        /// @param deltaTime=デルタタイム
        /// @return 次のフレームシーン
        SceneBase* Update(const float deltaTime)override;

        /// @brief  シーン更新処理
        void Draw()override;
    };
}