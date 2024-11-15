#pragma once

#include<vector>
#include<string>

namespace dream
{
    /// @brief �^�C�g������ޕʃ^�O
    static struct TitleObjectTag
    {
        std::string BACKGROUND = "background";
        std::string PLAYER = "player";
        std::string UI = "ui";

    }titleObjectTag;


    /// @brief  ���[�v����p
    static std::vector<std::string>TitleObjectTagOrder
    {
        titleObjectTag.BACKGROUND,
        titleObjectTag.PLAYER,
        titleObjectTag.UI
    };
}