#pragma once


namespace dream
{
    /// @brief  Fps�N���X
    class Fps
    {
    public:
        /// @brief  �R���X�g���N�^
        Fps();

        /// @brief  �f�X�g���N�^
        ~Fps();

        /// @brief  �X�V����
        void Update();

        /// @brief  �f���^�^�C���擾
        /// @return �f���^�^�C��
        float GetDeltaTime()const { return deltaTime; }

    private:
        float nowTime;  //���݂̎���
        float prevTime; //�ߋ��̎���
        float deltaTime;    //�f���^�^�C��;
    };
}