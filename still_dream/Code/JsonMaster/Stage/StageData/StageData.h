#pragma once
#include"../MasterStageData/MasterStageData.h"

namespace dream
{
    class StageData final
    {
    public:
        StageData(Json json);
        ~StageData();

        std::string GetMap1Csv() const { return mMap1Csv; }
        std::string GetCharaImg() const { return mCharaImg; }
        std::string GetMapImg() const { return mMapImg; }

    private:
        std::string mMap1Csv;
        std::string mCharaImg;
        std::string mMapImg;
    };
}