#include"GameManager.h"

namespace dream
{
    GameManager::GameManager()
    {
        //Log.txt‚ð¶¬‚µ‚È‚¢‚æ‚¤‚ÉÝ’è
        SetOutApplicationLogValidFlag(false);

        //Window‰Šú‰»
        Window::Init();
        //GameSetting‰Šú‰»
        GameSetting::Init();
        sceneManager.reset(new SceneManager);
    }

    GameManager::~GameManager()
    {

    }

    void GameManager::Finalize()
    {
        sceneManager->GameLoop();
    }
}