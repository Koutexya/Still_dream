#pragma once
#include<memory>

#include"../Stage/MasterStageData/MasterStageData.h"

namespace dream
{
    /// @brief  Jsonデータ管理クラス
    class JsonManager final
    {
    public:
        /// @brief  デストラクタ
        ~JsonManager();

        /// @brief  初期化
        static void InitJsonManager();

        /// @brief  ステージインスタンス
        /// @return　ステージデータ
        static class MasterStageData* StageDataInstance() { return jsonmanager->masterstagedata.get(); }

    private:
        /// @brief  コンストラクタ
        JsonManager();

        static std::unique_ptr<class JsonManager> jsonmanager;  //自身の実態

        std::unique_ptr<class MasterStageData> masterstagedata;//StageJsonの実態
    };
}