#include"BackGround.h"

namespace dream
{
    BackGround::BackGround()
        :GameObject(titleObjectTag.BackGround)
    {
        //画像読み込み
        BackGroundHandle = LoadGraph("JsonManager::titleDataInstance()->GetBackGround();");
    }

    BackGround::~BackGround()
    {
        //読み込みデータの削除
        DeleteGraph(BackGroundHandle);
    }

    void BackGround::Update(float deltaTime)
    {
        Draw();
    }

    void BackGround::Draw()
    {
        //背景の表示
        DrawGraph(0, 0, BackGroundHandle, TRUE);
    }
}