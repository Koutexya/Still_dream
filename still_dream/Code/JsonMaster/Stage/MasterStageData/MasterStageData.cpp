#include"MasterStageData.h"

namespace dream
{
    MasterStageData::MasterStageData()
    {
        //ファイルを読み込みインスタンス生成
        Json stageJson = ioutility.Anaysis("Code/JsonFile/StageData.json");
        stagedata.reset(new StageData(stageJson["Stage"]));
    }

    MasterStageData::~MasterStageData()
    {
        //処理なし
    }
}