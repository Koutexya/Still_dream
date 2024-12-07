#pragma once
#include<DxLib.h>
#include<unordered_map>
#include<memory>
#include<vector>

#include"../GameObject/GameObject.h"
#include"../GameObject/TitleObjectTag.h"
#include"../GameObject/Stage1ObjectTag.h"

class GameObject;

namespace dream
{
    class GameObjectManager final
    {
    public:
        /// @brief  デストラクタ
        ~GameObjectManager();

        /// @brief  マネージャーインスタンス生成
        static void Initialize();

        /// @brief  現在のシーンタグをセット
        static void NowSceneSet(std::vector<std::string> NowObjTag);

        /// @brief  オブジェクト登録
        /// @param  登録するオブジェクト
        static void Entry(GameObject* newObj);

        /// @brief  全オブジェクトの削除
        static void ReleaseAllObj();

        /// @brief  全オブジェクトの更新処理
        /// @param  デルタタイム
        static void Update(float deltaTime);

        /// @brief  全オブジェクトの描画
        static void Draw();

        /// @brief  タグ種類の初めのオブジェクトを返す
        /// @param  オブジェクトの種類
        /// @return 最初のオブジェクト
        GameObject* GetFirstGameObj(std::string tag);

    private:
        GameObject* gameObject;

        /// @brief  コンストラクタ
        GameObjectManager();

        static std::unique_ptr<GameObjectManager> mInstance;    //マネージャの実態
        std::vector<std::string> NowScene_ObjTag;    //現在のシーンのオブジェクトタグ
        std::unordered_map<std::string, std::vector<std::shared_ptr<GameObject>>> mObjects; //オブジェクトリスト
    };
}