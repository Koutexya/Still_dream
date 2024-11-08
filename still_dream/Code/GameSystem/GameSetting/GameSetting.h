#pragma once
#include<DxLib.h>
#include<memory>


namespace dream
{
    /// @brief  �Q�[���Z�b�e�B���O
    class GameSetting
    {
    public:
        /// @brief �R���X�g���N�^
        GameSetting();

        /// @brief �f�X�g���N�^
        ~GameSetting();

        /// @brief ����������
        static void Init();

        /// @brief ���C�u�����������O�̏���
        static void BeforeLibInit();

        /// @brief ���C�u������������̏���
        static void AfterLibInit();

    private:
        static std::unique_ptr<GameSetting> mSingleton;
    };
}