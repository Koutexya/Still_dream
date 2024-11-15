#include"BackGround.h"

namespace dream
{
    BackGround::BackGround()
        :GameObject(titleObjectTag.BackGround)
    {
        //�摜�ǂݍ���
        BackGroundHandle = LoadGraph("JsonManager::titleDataInstance()->GetBackGround();");
    }

    BackGround::~BackGround()
    {
        //�ǂݍ��݃f�[�^�̍폜
        DeleteGraph(BackGroundHandle);
    }

    void BackGround::Update(float deltaTime)
    {
        Draw();
    }

    void BackGround::Draw()
    {
        //�w�i�̕\��
        DrawGraph(0, 0, BackGroundHandle, TRUE);
    }
}