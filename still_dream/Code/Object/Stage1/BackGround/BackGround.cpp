#include"BackGround.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"

namespace dream
{
    BackGround::BackGround()
        :GameObject(stage1ObjectTag.BACKGROUND)
    {
        //画像読み込み
        BackGroundImg = LoadGraph("");
    }

    BackGround::~BackGround()
    {
        //読み込みデータの削除
        //DeleteGraph(BackGroundImg);
    }

    void BackGround::Draw()
    {
        //背景の表示
        DrawGraph(0, 0, BackGroundImg, TRUE);
    }
}