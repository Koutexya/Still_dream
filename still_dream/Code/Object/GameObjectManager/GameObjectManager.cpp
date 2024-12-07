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
        //前方宣言解放
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
        std::string tag = newObj->GetTagName();
        mInstance->mObjects[tag].emplace_back(newObj);
    }

    void GameObjectManager::ReleaseAllObj()
    {
        for (std::string& tag : mInstance->NowScene_ObjTag)
        {
            if (!mInstance->mObjects[tag].empty())
            {
                mInstance->mObjects[tag].clear();
            }
        }
    }

    void GameObjectManager::Update(float deltaTime)
    {
        for (std::string& tag : mInstance->NowScene_ObjTag)
        {
            // 該当タグにあるすべてのオブジェクトを更新
            for (auto& obj : mInstance->mObjects[tag])
            {
                //更新
                obj->Update(deltaTime);
            }
        }

    }

    void GameObjectManager::Draw()
    {
        for (std::string& tag : mInstance->NowScene_ObjTag)
        {
            for (auto& obj : mInstance->mObjects[tag])
            {
                obj->Draw();
            }
        }
    }

    GameObject* GameObjectManager::GetFirstGameObj(std::string tag)
    {
        //アクティブリストに何も入ってなかったら
        if (mInstance->mObjects[tag].size() == 0)
        {
            //nullptr 空 何もない
            return nullptr;
        }

        //もし入っていたらアクティブリストのオブジェクトの一番目(個数)を返す
        return mInstance->mObjects[tag][0].get();
    }
}