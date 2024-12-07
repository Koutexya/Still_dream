#pragma once
#include<DxLib.h>

#include"../../GameObject/GameObject.h"

namespace dream
{
    class Stage1BackGround : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Stage1BackGround();

        /// @brief  デストラクタ
        ~Stage1BackGround();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

    private:
        

        int BackGroundImg;
    };
}