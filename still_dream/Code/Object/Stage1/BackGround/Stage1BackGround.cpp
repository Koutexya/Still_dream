#include"Stage1BackGround.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"

namespace dream
{
    Stage1BackGround::Stage1BackGround()
        :GameObject(stage1ObjectTag.BACKGROUND)
    {
        //画像読み込み
        //BackGroundImg = LoadGraph("");
    }

    Stage1BackGround::~Stage1BackGround()
    {
        //読み込みデータの削除
        DeleteGraph(BackGroundImg);
    }

    void Stage1BackGround::Update(float deltaTime)
    {
        Draw();
    }

    void Stage1BackGround::Draw()
    {
        //背景の表示
        //DrawGraph(0, 0, BackGroundImg, TRUE);
        
    }
}