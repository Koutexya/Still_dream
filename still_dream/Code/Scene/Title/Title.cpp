#include<DxLib.h>

#include"Title.h"


namespace dream
{
    Title::Title()
        :SceneBase()
    {
        //ˆ—‚È‚µ
    }

    Title::~Title()
    {
        //ˆ—‚È‚µ
    }

    SceneBase* Title::Update(float deltaTime)
    {
        //ƒV[ƒ“Ø‚è‘Ö‚¦
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