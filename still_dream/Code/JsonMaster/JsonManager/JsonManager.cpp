#include"JsonManager.h"

namespace dream
{
    std::unique_ptr<JsonManager>JsonManager::jsonmanager = nullptr;

    JsonManager::JsonManager()
    {
        //�Ȃ�
    }

    JsonManager::~JsonManager()
    {
        //���
    }

    void JsonManager::InitJsonManager()
    {
        //���Ԃ��󂾂�����C���X�^���X����
        if (!jsonmanager)
        {
            jsonmanager.reset(new JsonManager);
        }
    }
}