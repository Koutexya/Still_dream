#pragma once
#include<DxLib.h>
#include<memory>


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
        static void SetSelect(int stage) { mInstance->SelectNum = stage; }

        /// @brief  選択したステージをゲット
        static int GetSelect() { return mInstance->SelectNum; }

    private:
        int SelectNum = 0;

        /// @brief  コンストラクタ
        StageSelect();

        static std::unique_ptr<StageSelect> mInstance;
    };
}