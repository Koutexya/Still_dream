#pragma once
#include"../SceneBase/SceneBase.h"

namespace dream
{
    /// @brief  �^�C�g����ʂ̐i�s�Ǘ��N���X
    class Title :public SceneBase
    {
    public:
        /// @brief  �R���X�g���N�^
        Title();

        /// @brief  �f�X�g���N�^
        ~Title();

        /// @brief  �V�[���X�V����
        /// @param deltaTime=�f���^�^�C��
        /// @return ���̃t���[���V�[��
        SceneBase* Update(const float deltaTime)override;

        /// @brief  �V�[���X�V����
        void Draw()override;
    };
}