#pragma once
#include"../MasterStageData/MasterStageData.h"

namespace dream
{
    class StageData final
    {
    public:
        StageData(Json json);
        ~StageData();

        std::string GetMapCsv() const { return mMapCsv; }
        std::string GetTutorialMapCsv() const { return mTutorialMapCsv; }
        std::string GetCharaImg() const { return mCharaImg; }
        std::string GetMapImg() const { return mMapImg; }

    private:
        std::string mMapCsv;
        std::string mTutorialMapCsv;
        std::string mCharaImg;
        std::string mMapImg;
    };
}