#include<DxLib.h>

#include"Title.h"


namespace dream
{
    Title::Title()
        :SceneBase()
    {
        //処理なし
    }

    Title::~Title()
    {
        //処理なし
    }

    SceneBase* Title::Update(float deltaTime)
    {
        //シーン切り替え
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