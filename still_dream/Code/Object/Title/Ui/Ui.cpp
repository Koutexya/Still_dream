#include"Ui.h"

namespace dream
{
    Ui::Ui()
        :GameObject(titleObjectTag.UI)
    {
        SetFontSize(64);
    }

    Ui::~Ui()
    {

    }

    void Ui::Update(float deltaTime)
    {
        Input();
        Draw();
    }

    void Ui::Input()
    {
        //タイトルのフェードイン表示が終わったら
        if (TitleFlg == false)
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
            else
            {
                //エンターでプレイ先を決定
                if (CheckHitKey(KEY_INPUT_RETURN))
                {
                    StageSelect::SetSelect(Pos);
                }
            }
        }
    }

    void Ui::Draw()
    {
        if (TitleScene == 0)
        {
            //タイトルのフェードイン表示
            if (TitleFlg)
            {
                for (int i = 0; i < 255; i++)
                {
                    // 描画輝度をセット
                    SetDrawBright(i, i, i);

                    // グラフィックを描画
                    DrawString(800, 500, "Still_Dream", GetColor(255, 255, 255));
                    ScreenFlip();
                }
                TitleFlg = false;
            }
            DrawString(800, 500, "Still_Dream", GetColor(255, 255, 255));
        }
        else
        {
            DrawString(850, 300, "Stage1", GetColor(255, 255, 255));
            DrawString(850, 500, "Stage2", GetColor(255, 255, 255));
            DrawFormatString(700, 700, GetColor(255, 255, 255), "音量 ←　%d　→", MusicVolume);

            DrawBox(700, Pos, 1250, Pos + 70, GetColor(255, 255, 255), FALSE);
        }
        
    }
}