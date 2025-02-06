#pragma once

#include<vector>
#include<string>

namespace dream
{
    /// @brief タイトル内種類別タグ
    static struct EndObjectTag
    {
        std::string BACKGROUND = "background";

    }endObjectTag;


    /// @brief  ループ制御用
    static std::vector<std::string>EndObjectTagOrder
    {
        endObjectTag.BACKGROUND
    };
}