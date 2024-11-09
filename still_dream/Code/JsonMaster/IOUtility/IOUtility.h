#pragma once
#include<fstream>
#include"../../IncludeFile/json.hpp"

using Json = nlohmann::json;


namespace dream
{
    class IOUtility final
    {
    public:
        /// @brief  �R���X�g���N�^
        IOUtility();

        /// @brief  �f�X�g���N�^
        ~IOUtility();

        /// @brief  Json�t�@�C���̃f�[�^���
        /// @param  fileName=�t�@�C����
        /// @return ��͍ς݂̃t�@�C���f�[�^
        Json Anaysis(std::string fileName);
    };
}