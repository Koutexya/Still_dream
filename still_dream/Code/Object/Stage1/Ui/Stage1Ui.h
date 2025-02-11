#pragma once
#include"../../GameObject/GameObject.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"

namespace dream
{
    class Stage1Ui : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Stage1Ui();

        /// @brief  デストラクタ
        ~Stage1Ui();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(const float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

    private:
        int TutorialUiHandle;
    };
}