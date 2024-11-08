#include"Window.h"

namespace dream
{
    //実態を空にする
    std::unique_ptr<Window> Window::mSingleton = nullptr;

    Window::Window()
    {
        //ウィンドウモードで起動
        ChangeWindowMode(TRUE);
        //画面モードの設定(1920,1080)
        SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), CORLOR_BIT);
        //PCの設定でウィンドウサイズの比率を変更してもプログラム内の設定サイズのまま表示する
        SetWindowSizeExtendRate(1.0);
        SetMainWindowText("Still_Dream");
    }

    Window::~Window()
    {

    }

    void Window::Init()
    {
        //実態に何も入っていない場合
        if (!mSingleton)
        {
            //実態内にインスタンス生成
            mSingleton.reset(new Window);
        }
    }
}