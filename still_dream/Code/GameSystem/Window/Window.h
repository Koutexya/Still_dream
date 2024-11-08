#pragma once
#include<DxLib.h>
#include<memory>


namespace dream
{
    
    /// @brief Windowクラス
    class Window
    {
    public:
        /// @brief デストラクタ
        ~Window();

        /// @brief 初期化処理
        static void Init();

        /// @brief ウィンドウサイズ取得処理
        /// @return ウィンドウサイズ
        static const VECTOR GetWindowSize() { return mSingleton->WINDOW_SIZE; }


    private:
        /// @brief コンストラクタ
        Window();

        const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0); //ウィンドウサイズ
        static std::unique_ptr<Window> mSingleton;  //自身の実態
        const int CORLOR_BIT = 16;  //カラービット
    };
}