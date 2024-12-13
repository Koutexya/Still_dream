#include"Stage1Map.h"

namespace dream
{
    Stage1Map::Stage1Map()
        :GameObject(stage1ObjectTag.MAP)
    {

    }

    Stage1Map::~Stage1Map()
    {

    }

    void Stage1Map::Update(float deltaTime)
    {
        Draw();
    }

    void Stage1Map::Draw()
    {
        DrawBox(700, 300, 800, 400, GetColor(255, 255, 255), FALSE);
    }


}