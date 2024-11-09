#pragma once
#include<memory>


namespace dream
{
    /// @brief  Json�f�[�^�Ǘ��N���X
    class JsonManager final
    {
    public:
        /// @brief  �f�X�g���N�^
        ~JsonManager();

        /// @brief  ������
        static void InitJsonManager();

    private:
        /// @brief  �R���X�g���N�^
        JsonManager();

        static std::unique_ptr<class JsonManager> jsonmanager;  //���g�̎���
    };
}