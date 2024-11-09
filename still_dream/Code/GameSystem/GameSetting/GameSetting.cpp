#include"GameSetting.h"


namespace dream
{
    //実態の初期化
    std::unique_ptr<GameSetting> GameSetting::mSingleton = nullptr;

    GameSetting::GameSetting()
    {
        BeforeLibInit();

        //DxLib初期化処理
        if (DxLib_Init() == -1)
        {
            //エラーが起きたら直ちに終了
            DebugBreak();
        }

        AfterLibInit();
    }

    GameSetting::~GameSetting()
    {
        //ライブラリの終了
        DxLib_End();
    }

    void GameSetting::Init()
    {
        //実態に何も入っていない場合
        if (!mSingleton)
        {
            //実態内にインスタンス生成
            mSingleton.reset(new GameSetting);
        }
    }

    void GameSetting::BeforeLibInit()
    {
        //アンチエイリアスの設定
        SetFullSceneAntiAliasingMode(4, 2);
    }

    void GameSetting::AfterLibInit()
    {
        //描画先を裏画面に設定
        SetDrawScreen(DX_SCREEN_BACK);
        //背景色の設定
        SetBackgroundColor(0, 0, 0);
    }
}