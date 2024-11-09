#pragma once
#include<DxLib.h>


namespace dream
{
    /// @brief  �V�[���̍X�V�����N���X
    class SceneBase
    {
    public:
        /// @brief  �R���X�g���N�^
        SceneBase();

        /// @brief  �f�X�g���N�^
        ~SceneBase();

        /// @brief  �V�[���X�V����
        /// @param deltaTime=�f���^�^�C��
        /// @return ���̃t���[���V�[��
        virtual SceneBase* Update(const float deltaTime) = 0;

        /// @brief  �V�[���`�揈��
        virtual void Draw() = 0;
    };
}