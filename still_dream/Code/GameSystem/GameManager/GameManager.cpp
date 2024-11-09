#include"GameManager.h"

namespace dream
{
    GameManager::GameManager()
    {
        //Log.txt‚ğ¶¬‚µ‚È‚¢‚æ‚¤‚Éİ’è
        SetOutApplicationLogValidFlag(false);

        //Window‰Šú‰»
        Window::Init();
        //GameSetting‰Šú‰»
        GameSetting::Init();

    }

    GameManager::~GameManager()
    {

    }

    void GameManager::Finalize()
    {

    }
}