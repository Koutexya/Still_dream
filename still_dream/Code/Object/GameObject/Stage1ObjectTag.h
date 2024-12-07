#pragma once
#include<vector>
#include<string>

namespace dream
{
    /// @brief Stage1内種類別タグ
    static struct Stage1ObjectTag
    {
        std::string BACKGROUND = "background";
        std::string MAP = "map";
        std::string PLAYER = "player";
        std::string UI = "ui";

    }stage1ObjectTag;


    /// @brief  ループ制御用
    static std::vector<std::string>Stage1ObjectTagOrder
    {
        stage1ObjectTag.BACKGROUND,
        stage1ObjectTag.MAP,
        stage1ObjectTag.PLAYER,
        stage1ObjectTag.UI
    };
}