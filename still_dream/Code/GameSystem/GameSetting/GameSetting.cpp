#include"GameSetting.h"


namespace dream
{
    //���Ԃ̏�����
    std::unique_ptr<GameSetting> GameSetting::mSingleton = nullptr;

    GameSetting::GameSetting()
    {
        BeforeLibInit();

        //DxLib����������
        if (DxLib_Init() == -1)
        {
            //�G���[���N�����璼���ɏI��
            DebugBreak();
        }

        AfterLibInit();
    }

    GameSetting::~GameSetting()
    {
        //���C�u�����̏I��
        DxLib_End();
    }

    void GameSetting::Init()
    {
        //���Ԃɉ��������Ă��Ȃ��ꍇ
        if (!mSingleton)
        {
            //���ԓ��ɃC���X�^���X����
            mSingleton.reset(new GameSetting);
        }
    }

    void GameSetting::BeforeLibInit()
    {
        //�A���`�G�C���A�X�̐ݒ�
        SetFullSceneAntiAliasingMode(4, 2);
    }

    void GameSetting::AfterLibInit()
    {
        //�`���𗠉�ʂɐݒ�
        SetDrawScreen(DX_SCREEN_BACK);
        //�w�i�F�̐ݒ�
        SetBackgroundColor(0, 0, 0);
    }
}