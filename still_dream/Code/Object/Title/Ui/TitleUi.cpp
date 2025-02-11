#include"TitleUi.h"

namespace dream
{
    TitleUi::TitleUi()
        :GameObject(titleObjectTag.UI)
    {
        SetFontSize(64);
        StageSelect::Initialize();

        TitleNameHandle = LoadGraph("Asset/Image/TitleName.png");
        TitlePushHandle = LoadGraph("Asset/Image/TitlePush.png");
        TitleSelectHandle = LoadGraph("Asset/Image/TitleSelect.png");
        //TitleMovieHandle = LoadGraph("Asset/Movie/Title.mp4");
        
        
        ChangeVolumeSoundMem(MusicVolume * 2.5, BgmHandle);
        BgmHandle = LoadSoundMem("Asset/Sound/Learning.mp3");
        PlaySoundMem(BgmHandle, DX_PLAYTYPE_LOOP, TRUE);
    }

    TitleUi::~TitleUi()
    {
        DeleteSoundMem(BgmHandle);
        DeleteGraph(TitleNameHandle);
        DeleteGraph(TitlePushHandle);
        DeleteGraph(TitleSelectHandle);
        //DeleteGraph(TitleMovieHandle);

    }

    void TitleUi::Update(const float deltaTime)
    {
        Input(deltaTime);  
    }

    void TitleUi::Input(const float deltaTime)
    {
        ChangeVolumeSoundMem(MusicVolume * 2.5, BgmHandle);
        if (TitleScene == 0)
        {
            //タイトル表示から次に進む
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                TitleScene = 1;
            }
        }
        if (TitleScene == 1)
        {
            //上下で移動
            if (CheckHitKey(KEY_INPUT_UP))
            {
                if (KeyUpFlag == false)
                {
                    if (Pos != 300)
                    {
                        Pos -= 200;
                    }
                    KeyUpFlag = true;
                }
            }
            else
            {
                KeyUpFlag = false;
            }
            if (CheckHitKey(KEY_INPUT_DOWN))
            {
                if (KeyDownFlag == false)
                {
                    if (Pos != 700)
                    {
                        Pos += 200;
                    }
                    KeyDownFlag = true;
                }
            }
            else
            {
                KeyDownFlag = false;
            }
            //エンターでプレイ先を決定
            if (CheckHitKey(KEY_INPUT_RETURN))
            {
                if (Pos == 300)
                {
                    StageSelect::SetSelect(stageTag.Stage1);
                }
                if (Pos == 500)
                {
                    StageSelect::SetSelect(stageTag.Stage2);
                }
                StopSoundMem(BgmHandle);
            }
            

            //音量変更
            if (Pos == 700)
            {
                if (CheckHitKey(KEY_INPUT_LEFT))
                {
                    if (KeyLeftFlag == false)
                    {
                        if (MusicVolume > 0)
                        {
                            MusicVolume -= 10;
                        }
                        KeyLeftFlag = true;
                    }
                }
                else
                {
                    KeyLeftFlag = false;
                }
                if (CheckHitKey(KEY_INPUT_RIGHT))
                {
                    if (KeyRightFlag == false)
                    {
                        if (MusicVolume < 100)
                        {
                            MusicVolume += 10;
                        }
                        KeyRightFlag = true;
                    }
                }
                else
                {
                    KeyRightFlag = false;
                }
            }
        }
    }

    void TitleUi::Draw()
    {
        if (TitleScene == 0)
        {
            DrawGraph(0, 0, TitlePushHandle, TRUE);
            //タイトルのフェードイン表示 画像フェードイン出来てない！！
            //if (TitleFlg)
            //{
            //    for (int i = 0; i < 255; i++)
            //    {
            //        // 描画輝度をセット
            //        SetDrawBright(i, i, i);
            //        // グラフィックを描画
            //        DrawGraph(0, 0, TitleNameHandle, TRUE);
            //        ScreenFlip();
            //    }
            //    TitleFlg = false;
            //}
            DrawGraph(0, 0, TitleNameHandle, TRUE);

        }
        else
        {
            DrawGraph(0, 0, TitleSelectHandle, TRUE);
            //DrawString(850, 300, "Stage1", GetColor(255, 255, 255));
            ////DrawString(850, 500, "Stage2", GetColor(255, 255, 255));
            DrawFormatString(980, 700, GetColor(0, 0, 0), "%d", MusicVolume);

            DrawBox(700, Pos, 1250, Pos + 70, GetColor(255, 255, 255), FALSE);
        }
        
    }
}