#pragma once

#include<string>

namespace dream
{
    /// @brief ステージ種類別タグ
    static struct StageTag
    {
        std::string Stage1 = "stage1";
        std::string Stage2 = "stage2";

        std::string GameClear = "gameclear";
        std::string GameOver = "gameover";

    }stageTag;
}