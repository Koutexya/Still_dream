#include"GameManager.h"

namespace dream
{
    GameManager::GameManager()
    {
        //Log.txt�𐶐����Ȃ��悤�ɐݒ�
        SetOutApplicationLogValidFlag(false);

        //Window������
        Window::Init();
        //GameSetting������
        GameSetting::Init();

    }

    GameManager::~GameManager()
    {

    }

    void GameManager::Finalize()
    {

    }
}