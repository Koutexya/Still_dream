#include"StageData.h"

namespace dream
{
    StageData::StageData(Json json)
    {
        mMapCsv = json["MapCsv"];
        mTutorialMapCsv = json["TutorialMap"];
        mCharaImg = json["CharaImg"];
        mMapImg = json["MapImg"];
    }

    StageData::~StageData()
    {
        //ˆ—‚È‚µ
    }
}