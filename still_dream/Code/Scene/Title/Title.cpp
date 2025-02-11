#include<DxLib.h>

#include"Title.h"
#include"../Stage1/Stage1.h"


namespace dream
{
    Title::Title()
    {
        //現在のシーン
        GameObjectManager::NowSceneSet(TitleObjectTagOrder);
        //生成
        GameObjectManager::Entry(new TitleBackGround);
        GameObjectManager::Entry(new TitleUi);
    }

    Title::~Title()
    {
        //処理なし
    }

    SceneBase* Title::Update(const float deltaTime)
    {
        //全ゲームオブジェクトの更新
        GameObjectManager::Update(deltaTime);
        
        //シーン切り替え
        if (stageTag.Stage1 == StageSelect::GetSelect())
        {
            GameObjectManager::ReleaseAllObj();
            return new Stage1;
        }
        if (stageTag.Stage2 == StageSelect::GetSelect())
        {
            GameObjectManager::ReleaseAllObj();
            return new Stage1;
        }
        return this;
    }

    void Title::Draw()
    {
        //全ゲームオブジェクトの描画
        GameObjectManager::Draw();
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
    }
}