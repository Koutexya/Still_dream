#pragma once
#include<DxLib.h>
#include<memory>


namespace dream
{
    /// @brief  ゲームセッティング
    class GameSetting
    {
    public:
        /// @brief コンストラクタ
        GameSetting();

        /// @brief デストラクタ
        ~GameSetting();

        /// @brief 初期化処理
        static void Init();

        /// @brief ライブラリ初期化前の処理
        static void BeforeLibInit();

        /// @brief ライブラリ初期化後の処理
        static void AfterLibInit();

    private:
        static std::unique_ptr<GameSetting> mSingleton;
    };
}