#include<DxLib.h>

#include"End.h"
#include"../Title/Title.h"

namespace dream
{
    End::End()
    {
        //現在のシーン
        GameObjectManager::NowSceneSet(EndObjectTagOrder);
        //生成
        GameObjectManager::Entry(new EndBackGround);
    }

    End::~End()
    {
        //処理なし
    }

    SceneBase* End::Update(float deltaTime)
    {
        //全ゲームオブジェクトの更新
        GameObjectManager::Update(deltaTime);

        //シーン切り替え
        if (CheckHitKeyAll())
        {
            GameObjectManager::ReleaseAllObj();
            return new Title;
        }
        return this;
    }

    void End::Draw()
    {
        //全ゲームオブジェクトの描画
        GameObjectManager::Draw();
        //DrawFormatString(0, 0, GetColor(255, 255, 255), "end");
    }
}