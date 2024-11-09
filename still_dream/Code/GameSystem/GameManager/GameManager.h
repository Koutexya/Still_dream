#pragma once
#include<DxLib.h>
#include<memory>

#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"


namespace dream
{
    /// @brief  ゲーム全体の進行管理クラス
    class GameManager final
    {
    public:
        /// @brief  コンストラクタ
        GameManager();

        /// @brief  デストラクタ
        ~GameManager();

        /// @brief  後処理
        void Finalize();

    private:

    };
}