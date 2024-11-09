#pragma once
#include<memory>
#include<stack>

#include"../SceneBase/SceneBase.h"
#include"../../FPS/Fps.h"

namespace dream
{
    /// @brief  �V�[���Ǘ�
    class SceneManager final
    {
    public:
        /// @brief  �R���X�g���N�^
        SceneManager();

        /// @brief  �f�X�g���N�^
        ~SceneManager();

        /// @brief  �Q�[�����[�v
        void GameLoop();

        /// @brief  �V�[���X�V����
        void UpdateScene();

        /// @brief  �V�[���`�揈��
        void DrawScene();

        /// @brief  �V�[���؂�ւ�����
        void ChangeScene();

    private:
        std::unique_ptr<class Fps> mFps;    //�^�C���}�l�[�W���[
        std::stack<std::shared_ptr<class SceneBase>> mNowScene; //���݂̃V�[��
        SceneBase* mHoldScene;  //���̃V�[��
    };
}