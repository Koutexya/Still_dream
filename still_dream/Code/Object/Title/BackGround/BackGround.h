#pragma once
#include<DxLib.h>
#include"../../GameObject/GameObject.h"


namespace dream
{
    class BackGround : public GameObject
    {
    public:
        /// @brief  �R���X�g���N�^
        BackGround();

        /// @brief  �f�X�g���N�^
        ~BackGround();

        /// @brief  �X�V����
        /// @param  �f���^�^�C��
        void Update(float deltaTime)override;

        /// @brief  �`�揈��
        void Draw()override;

    private:
        int BackGroundHandle;
    };
}