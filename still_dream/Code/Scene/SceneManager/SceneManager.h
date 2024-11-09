#pragma once
#include<memory>
#include<stack>

#include"../SceneBase/SceneBase.h"
#include"../../FPS/Fps.h"

namespace dream
{
    /// @brief  シーン管理
    class SceneManager final
    {
    public:
        /// @brief  コンストラクタ
        SceneManager();

        /// @brief  デストラクタ
        ~SceneManager();

        /// @brief  ゲームループ
        void GameLoop();

        /// @brief  シーン更新処理
        void UpdateScene();

        /// @brief  シーン描画処理
        void DrawScene();

        /// @brief  シーン切り替え処理
        void ChangeScene();

    private:
        std::unique_ptr<class Fps> mFps;    //タイムマネージャー
        std::stack<std::shared_ptr<class SceneBase>> mNowScene; //現在のシーン
        SceneBase* mHoldScene;  //次のシーン
    };
}