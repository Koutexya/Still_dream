#pragma once
#include<DxLib.h>
#include<memory>


namespace dream
{
    
    /// @brief Window�N���X
    class Window
    {
    public:
        /// @brief �f�X�g���N�^
        ~Window();

        /// @brief ����������
        static void Init();

        /// @brief �E�B���h�E�T�C�Y�擾����
        /// @return �E�B���h�E�T�C�Y
        static const VECTOR GetWindowSize() { return mSingleton->WINDOW_SIZE; }


    private:
        /// @brief �R���X�g���N�^
        Window();

        const VECTOR WINDOW_SIZE = VGet(1920, 1080, 0); //�E�B���h�E�T�C�Y
        static std::unique_ptr<Window> mSingleton;  //���g�̎���
        const int CORLOR_BIT = 16;  //�J���[�r�b�g
    };
}