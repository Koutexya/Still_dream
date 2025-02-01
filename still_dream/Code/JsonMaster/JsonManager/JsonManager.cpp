#include"JsonManager.h"

namespace dream
{
    std::unique_ptr<JsonManager>JsonManager::jsonmanager = nullptr;

    JsonManager::JsonManager()
        :masterstagedata(new MasterStageData)
    {
        //なし
    }

    JsonManager::~JsonManager()
    {
        //解放
        masterstagedata.release();
    }

    void JsonManager::InitJsonManager()
    {
        //実態が空だったらインスタンス生成
        if (!jsonmanager)
        {
            jsonmanager.reset(new JsonManager);
        }
    }
}