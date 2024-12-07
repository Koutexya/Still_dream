#include"StageSelect.h"

namespace dream
{
    //実体の中身を空に
    std::unique_ptr<StageSelect>StageSelect::mInstance = nullptr;

    StageSelect::StageSelect()
    {
        mInstance = nullptr;
    }

    StageSelect::~StageSelect()
    {

    }

    void StageSelect::Initialize()
    {
        //自身の中身が空ならインスタンス生成
        if (!mInstance)
        {
            mInstance.reset(new StageSelect);
        }
    }
}