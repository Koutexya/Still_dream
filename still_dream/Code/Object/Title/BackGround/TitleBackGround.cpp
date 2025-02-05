#include"TitleBackGround.h"

namespace dream
{
    TitleBackGround::TitleBackGround()
        :GameObject(titleObjectTag.BACKGROUND)
    {
        //画像読み込み
        BackGroundHandle = LoadGraph("JsonManager::titleDataInstance()->GetBackGround();");
    }

    TitleBackGround::~TitleBackGround()
    {
        //読み込みデータの削除
        DeleteGraph(BackGroundHandle);
    }

    void TitleBackGround::Update(float deltaTime)
    {
        
    }

    void TitleBackGround::Draw()
    {
        //背景の表示
        DrawGraph(0, 0, BackGroundHandle, TRUE);
        
    }
}