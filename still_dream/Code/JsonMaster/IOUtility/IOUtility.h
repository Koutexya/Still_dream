#pragma once
#include<fstream>
#include"../../IncludeFile/json.hpp"

using Json = nlohmann::json;


namespace dream
{
    class IOUtility final
    {
    public:
        /// @brief  コンストラクタ
        IOUtility();

        /// @brief  デストラクタ
        ~IOUtility();

        /// @brief  Jsonファイルのデータ解析
        /// @param  fileName=ファイル名
        /// @return 解析済みのファイルデータ
        Json Anaysis(std::string fileName);
    };
}