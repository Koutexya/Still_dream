#include<DxLib.h>

#include"Stage1.h"
#include"../Title/Title.h"

namespace dream
{
    Stage1::Stage1()
    {
        //現在のシーン
        GameObjectManager::NowSceneSet(Stage1ObjectTagOrder);
        //生成
        GameObjectManager::Entry(new Stage1BackGround);
    }

    Stage1::~Stage1()
    {

    }

    SceneBase* Stage1::Update(float deltaTime)
    {
        //全ゲームオブジェクトの更新
        GameObjectManager::Update(deltaTime);

        //シーン切り替え
        ////死んだ場合
        //GameObjectManager::ReleaseAllObj();
        //return new Stage1;
        ////タイトルに戻るボタン押した場合
        //GameObjectManager::ReleaseAllObj();
        //return new Title;

        return this;
    }

    void Stage1::Draw()
    {
        //全ゲームオブジェクトの描画
        GameObjectManager::Draw();
        DrawFormatString(0, 0, GetColor(255, 255, 255), "stage1");
    }
}