#pragma once
#include"../../GameObject/GameObject.h"

namespace dream
{
    class Ui : public GameObject
    {
    public:
        /// @brief  �R���X�g���N�^
        Ui();

        /// @brief  �f�X�g���N�^
        ~Ui();

        /// @brief  �X�V����
        /// @param  �f���^�^�C��
        void Update(float deltaTime)override;

        /// @brief  �`�揈��
        void Draw()override;

    private:

    };
}