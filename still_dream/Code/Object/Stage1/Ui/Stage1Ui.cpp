#include"Stage1Ui.h"

namespace dream
{
    Stage1Ui::Stage1Ui()
        :GameObject(stage1ObjectTag.UI)
    {
        TutorialUiHandle = LoadGraph("Asset/Image/TutorialUi.png");
    }

    Stage1Ui::~Stage1Ui()
    {
        //DeleteGraph(TutorialUiHandle);
    }

    void Stage1Ui::Update(float deltaTime)
    {

    }

    void Stage1Ui::Draw()
    {
        //âÊñ ÉTÉCÉY(1920,1080)
        //DrawLine(0, 540, 1920, 540, GetColor(255, 255, 0));
        DrawGraph(0, 0, TutorialUiHandle, TRUE);
        //DrawBox(100, 100, 176, 176, GetColor(255, 255, 0), TRUE);
    }
}