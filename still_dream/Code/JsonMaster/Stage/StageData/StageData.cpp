#include"StageData.h"

namespace dream
{
    StageData::StageData(Json json)
    {
        mMap1Csv = json["Map1Csv"];
        mCharaImg = json["CharaImg"];
        mMapImg = json["MapImg"];
    }

    StageData::~StageData()
    {
        //ˆ—‚È‚µ
    }
}