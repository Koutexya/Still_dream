#pragma once

#include<vector>
#include<string>

namespace dream
{
    /// @brief タイトル内種類別タグ
    static struct TitleObjectTag
    {
        std::string BACKGROUND = "background";
        std::string PLAYER = "player";
        std::string UI = "ui";

    }titleObjectTag;


    /// @brief  ループ制御用
    static std::vector<std::string>TitleObjectTagOrder
    {
        titleObjectTag.BACKGROUND,
        titleObjectTag.PLAYER,
        titleObjectTag.UI
    };
}