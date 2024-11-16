#include <DxLib.h>
#include"GameSystem/GameManager/GameManager.h"

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
//{
//    unsigned int Cr;
//
//    if (DxLib_Init() == -1)    // �c�w���C�u��������������
//    {
//        return -1;    // �G���[���N�����璼���ɏI��
//    }
//
//     //���F�̒l���擾
//    Cr = GetColor(255, 255, 255);
//
//     //������̕`��
//    DrawString(250, 240 - 32, "Hello C World!", Cr);
//
//    WaitKey();        // �L�[�̓��͑҂�(�wWaitKey�x���g�p)
//
//    DxLib_End();        // �c�w���C�u�����g�p�̏I������
//
//    return 0;        // �\�t�g�̏I��
//}

using namespace dream;

int WINAPI _stdcall WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    //�Q�[���̃V�[���Ǘ�
    std::shared_ptr<GameManager> gamemanager(new GameManager);
    gamemanager->Finalize();

    return 0;
}