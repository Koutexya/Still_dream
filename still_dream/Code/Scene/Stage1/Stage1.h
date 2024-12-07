#pragma once
#include"../SceneBase/SceneBase.h"
#include"../../Object/GameObjectManager/GameObjectManager.h"
#include"../../Object/GameObject/Stage1ObjectTag.h"
#include"../../Object/Stage1/BackGround/Stage1BackGround.h"

namespace dream
{
    /// @brief  Stage1画面の進行管理クラス
    class Stage1 :public SceneBase
    {
    public:
        /// @brief  コンストラクタ
        Stage1();

        /// @brief  デストラクタ
        ~Stage1();

        /// @brief  シーン更新処理
        /// @param deltaTime=デルタタイム
        /// @return 次のフレームシーン
        SceneBase* Update(const float deltaTime)override;

        /// @brief  シーン更新処理
        void Draw()override;

    private:
    };
}