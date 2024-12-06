#include<DxLib.h>

#include"Title.h"


namespace dream
{
    Title::Title()
    {
        //現在のシーン
        GameObjectManager::NowSceneSet(TitleObjectTagOrder);
        //生成
        GameObjectManager::Entry(new BackGround);
        GameObjectManager::Entry(new Ui);
    }

    Title::~Title()
    {
        //処理なし
    }

    SceneBase* Title::Update(float deltaTime)
    {
        //全ゲームオブジェクトの更新
        GameObjectManager::Update(deltaTime);
        
        //シーン切り替え
        /*if (CheckHitKey(KEY_INPUT_RETURN))
        {
            GameObjectManager::ReleaseAllObj();
            return new Play;
        }*/
        return this;
    }

    void Title::Draw()
    {
        //全ゲームオブジェクトの描画
        GameObjectManager::Draw();
        DrawFormatString(0, 0, GetColor(255, 255, 255), "title");
    }
}