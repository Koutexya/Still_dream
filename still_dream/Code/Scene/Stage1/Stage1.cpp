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
        GameObjectManager::Entry(new Stage1Map);
        GameObjectManager::Entry(new Stage1Player);
        GameObjectManager::Entry(new Stage1Ui);
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
        if (stageTag.GameOver == StageSelect::GetGameFlag())
        {
            GameObjectManager::ReleaseAllObj();
            StageSelect::finalize();
            return new Stage1;
        }
        ////クリアした場合
        if (stageTag.GameClear == StageSelect::GetGameFlag())
        {
            GameObjectManager::ReleaseAllObj();
            StageSelect::finalize();
            return new Title;
        }
        ////タイトルに戻るボタン押した場合
        if (CheckHitKey(KEY_INPUT_TAB))
        {
            GameObjectManager::ReleaseAllObj();
            return new Title;
        }

        return this;
    }

    void Stage1::Draw()
    {
        //全ゲームオブジェクトの描画
        GameObjectManager::Draw();
        DrawFormatString(0, 0, GetColor(255, 255, 255), "stage1");
    }
}