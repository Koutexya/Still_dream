#include"IOUtility.h"

namespace dream
{
    IOUtility::IOUtility()
    {
        //なし
    }

    IOUtility::~IOUtility()
    {
        //なし
    }

    Json IOUtility::Anaysis(std::string fileName)
    {
        Json result;

        //ファイル読み込み
        std::ifstream ifs(fileName.c_str());
        //ファイルの解析
        result = Json::parse(ifs);

        ifs.close();
        return result;
    }
}