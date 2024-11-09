#include"GameManager.h"

namespace dream
{
    GameManager::GameManager()
    {
        //Log.txtを生成しないように設定
        SetOutApplicationLogValidFlag(false);

        //Window初期化
        Window::Init();
        //GameSetting初期化
        GameSetting::Init();

    }

    GameManager::~GameManager()
    {

    }

    void GameManager::Finalize()
    {

    }
}