#include<DxLib.h>
#include<assert.h>

#include"SceneManager.h"


namespace dream
{
    SceneManager::SceneManager()
        :mHoldScene(nullptr)
        , mFps(new Fps)
    {
        //����������
        //������GameObjectManager��Init

        //���݂̃V�[�����^�C�g���ɐݒ�
        
    }


    SceneManager::~SceneManager()
    {
        //�����Ȃ�
    }

    void SceneManager::GameLoop()
    {
        //�G�X�P�[�v�L�[��������邩�E�B���h�E��������܂Ń��[�v
        while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
        {
            //�V�[���̗���
            UpdateScene();  //�X�V����
            ChangeScene();  //�؂�ւ�����
            DrawScene();    //�`�揈��
        }
    }

    void SceneManager::UpdateScene()
    {
        //���݂̃V�[�����X�V����mHoldScene�ɑ��
        mFps->Update();
        mHoldScene = mNowScene.top()->Update(mFps->GetDeltaTime());
    }

    void SceneManager::DrawScene()
    {
        ClearDrawScreen();  //��ʂ��N���A
        mNowScene.top()->Draw();    //���̃V�[����\��
        ScreenFlip();   //����ʂ̓��e��\��ʂɔ��f
    }

    void SceneManager::ChangeScene()
    {
        //���̃V�[���������ł͂Ȃ�������
        if (mNowScene.top().get() != mHoldScene)
        {
            //���݂̃V�[�����폜�����̃V�[���ɐ؂�ւ���
            mNowScene.pop();    //.pop()�v�f���폜����
            mNowScene.emplace(mHoldScene);  //.emplace()�V�����v�f��}������

            //�V�[���̒��g����̏ꍇ�v���O�����������I��
            assert(!mNowScene.empty()); //.empty()�R���e�i���󂩂ǂ�������
        }
    }
}