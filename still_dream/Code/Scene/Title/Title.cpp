#include<DxLib.h>

#include"Title.h"


namespace dream
{
    Title::Title()
        :SceneBase()
    {
        //�����Ȃ�
    }

    Title::~Title()
    {
        //�����Ȃ�
    }

    SceneBase* Title::Update(float deltaTime)
    {
        //�V�[���؂�ւ�
        if (CheckHitKey(KEY_INPUT_SPACE))
        {
            
        }
        return this;
    }

    void Title::Draw()
    {
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
    }
}