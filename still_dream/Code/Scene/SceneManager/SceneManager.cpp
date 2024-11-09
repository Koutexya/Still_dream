#include<DxLib.h>
#include<assert.h>

#include"SceneManager.h"


namespace dream
{
    SceneManager::SceneManager()
        :mHoldScene(nullptr)
        , mFps(new Fps)
    {
        //初期化処理
        //ここにGameObjectManagerのInit

        //現在のシーンをタイトルに設定
        
    }


    SceneManager::~SceneManager()
    {
        //処理なし
    }

    void SceneManager::GameLoop()
    {
        //エスケープキーが押されるかウィンドウが閉じられるまでループ
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            //シーンの流れ
            UpdateScene();  //更新処理
            ChangeScene();  //切り替え処理
            DrawScene();    //描画処理
        }
    }

    void SceneManager::UpdateScene()
    {
        //現在のシーンを更新してmHoldSceneに代入
        mFps->Update();
        mHoldScene = mNowScene.top()->Update(mFps->GetDeltaTime());
    }

    void SceneManager::DrawScene()
    {
        ClearDrawScreen();  //画面をクリア
        mNowScene.top()->Draw();    //次のシーンを表示
        ScreenFlip();   //裏画面の内容を表画面に反映
    }

    void SceneManager::ChangeScene()
    {
        //次のシーンが同じではなかったら
        if (mNowScene.top().get() != mHoldScene)
        {
            //現在のシーンを削除し次のシーンに切り替える
            mNowScene.pop();    //.pop()要素を削除する
            mNowScene.emplace(mHoldScene);  //.emplace()新しい要素を挿入する

            //シーンの中身が空の場合プログラムを強制終了
            assert(!mNowScene.empty()); //.empty()コンテナが空かどうか判定
        }
    }
}