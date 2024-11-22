#include"GameObjectManager.h"

namespace dream
{
    //実体の中身を空に
    std::unique_ptr<GameObjectManager>GameObjectManager::mInstance = nullptr;


    GameObjectManager::GameObjectManager()
        :mObjects()
    {
        mInstance = nullptr;
    }

    GameObjectManager::~GameObjectManager()
    {
        //前方宣言開放
        delete gameObject;
    }

    void GameObjectManager::Initialize()
    {
        //自身の中身が空ならインスタンス生成
        if (!mInstance)
        {
            mInstance.reset(new GameObjectManager);
        }
    }

    void GameObjectManager::NowSceneSet(std::vector<std::string> NowObjTag)
    {
        mInstance->NowScene_ObjTag = NowObjTag;
    }

    void GameObjectManager::Entry(GameObject* newObj)
    {
        //タグの検索をしてオブジェクト登録
    }

}