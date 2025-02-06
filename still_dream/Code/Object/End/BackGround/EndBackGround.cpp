#include"EndBackGround.h"

namespace dream
{
    EndBackGround::EndBackGround()
        :GameObject(endObjectTag.BACKGROUND)
    {
        //画像読み込み
        BackMovieHandle = LoadGraph("Asset/Movie/GameClear.mp4");
        PlayMovieToGraph(BackMovieHandle);

        ChangeVolumeSoundMem(100, BgmHandle);
        BgmHandle = LoadSoundMem("Asset/Sound/Afterglow.mp3");
        PlaySoundMem(BgmHandle, DX_PLAYTYPE_BACK, TRUE);
    }

    EndBackGround::~EndBackGround()
    {
        //読み込みデータの削除
        DeleteGraph(BackMovieHandle);
    }

    void EndBackGround::Update(float deltaTime)
    {
        if (CheckHitKeyAll())
        {
            StopSoundMem(BgmHandle);
        }
    }

    void EndBackGround::Draw()
    {
        ChangeVolumeSoundMem(100, BgmHandle);

        //DrawGraph(0, 0, BackMovieHandle, TRUE);
        //動画拡大表示
        DrawExtendGraph(0, 0, 1981, 1081, BackMovieHandle, TRUE);
       
        
    }
}