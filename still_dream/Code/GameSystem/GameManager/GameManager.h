#pragma once
#include<DxLib.h>
#include<memory>

#include"../Window/Window.h"
#include"../GameSetting/GameSetting.h"


namespace dream
{
    /// @brief  �Q�[���S�̂̐i�s�Ǘ��N���X
    class GameManager final
    {
    public:
        /// @brief  �R���X�g���N�^
        GameManager();

        /// @brief  �f�X�g���N�^
        ~GameManager();

        /// @brief  �㏈��
        void Finalize();

    private:

    };
}