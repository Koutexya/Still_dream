#pragma once
#include<DxLib.h>
#include<memory>

#include"StageTag.h"


namespace dream
{
    class StageSelect final
    {
    public:
        /// @brief  デストラクタ
        ~StageSelect();

        /// @brief  初期化
        static void Initialize();

        /// @brief  選択したステージをセット
        static void SetSelect(std::string stage) { mInstance->SelectNum = stage; }

        /// @brief  選択したステージをゲット
        static std::string GetSelect() { return mInstance->SelectNum; }

    private:
        std::string SelectNum;

        /// @brief  コンストラクタ
        StageSelect();

        static std::unique_ptr<StageSelect> mInstance;
    };
}