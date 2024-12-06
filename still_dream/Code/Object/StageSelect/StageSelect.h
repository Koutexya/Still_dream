#pragma once
#include<DxLib.h>


namespace dream
{
    class StageSelect final
    {
    public:
        /// @brief  コンストラクタ
        StageSelect();

        /// @brief  デストラクタ
        ~StageSelect();

        /// @brief  選択したステージをセット
        void SetSelect(int stage) { SelectNum = stage; }

        /// @brief  選択したステージをゲット
        int GetSelect() { return SelectNum; }

    private:
        int SelectNum = 0;
    };
}