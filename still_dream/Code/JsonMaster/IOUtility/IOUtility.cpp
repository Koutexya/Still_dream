#include"IOUtility.h"

namespace dream
{
    IOUtility::IOUtility()
    {
        //�Ȃ�
    }

    IOUtility::~IOUtility()
    {
        //�Ȃ�
    }

    Json IOUtility::Anaysis(std::string fileName)
    {
        Json result;

        //�t�@�C���ǂݍ���
        std::ifstream ifs(fileName.c_str());
        //�t�@�C���̉��
        result = Json::parse(ifs);

        ifs.close();
        return result;
    }
}