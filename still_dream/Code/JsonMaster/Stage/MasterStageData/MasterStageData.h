#pragma once
#include<memory>

#include"../../IOUtility/IOUtility.h"
#include"../StageData/StageData.h"

namespace dream
{
    /// <summary>
    /// StageJsonデータ管理クラス
    /// </summary>
    class MasterStageData final
    {
    public:
        MasterStageData();

        ~MasterStageData();

        class StageData* StageDataInstance() { return stagedata.get(); }
        
    private:
        IOUtility ioutility;    //IOUtilityインスタンス

        std::unique_ptr<class StageData> stagedata;
    };
}