#include"Window.h"

namespace dream
{
    //���Ԃ���ɂ���
    std::unique_ptr<Window> Window::mSingleton = nullptr;

    Window::Window()
    {
        //�E�B���h�E���[�h�ŋN��
        ChangeWindowMode(TRUE);
        //��ʃ��[�h�̐ݒ�(1920,1080)
        SetGraphMode(static_cast<int>(WINDOW_SIZE.x), static_cast<int>(WINDOW_SIZE.y), CORLOR_BIT);
        //PC�̐ݒ�ŃE�B���h�E�T�C�Y�̔䗦��ύX���Ă��v���O�������̐ݒ�T�C�Y�̂܂ܕ\������
        SetWindowSizeExtendRate(1.0);
        SetMainWindowText("Still_Dream");
    }

    Window::~Window()
    {

    }

    void Window::Init()
    {
        //���Ԃɉ��������Ă��Ȃ��ꍇ
        if (!mSingleton)
        {
            //���ԓ��ɃC���X�^���X����
            mSingleton.reset(new Window);
        }
    }
}