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
        if (TitleFlg == false)
        {
            if (CheckHitKey(KEY_INPUT_SPACE))
            {
                TitleScene = 1;
            }
            if (TitleScene == 1)
            {
                if (CheckHitKey(KEY_INPUT_UP))
                {
                    if (KeyUpFlag == 0)
                    {
                        if (Pos != 300)
                        {
                            Pos -= 200;
                        }
                        KeyUpFlag = 1;
                    }
                }
                else
                {
                    KeyUpFlag = 0;
                }
                if (CheckHitKey(KEY_INPUT_DOWN))
                {
                    if (KeyDownFlag == 0)
                    {
                        if (Pos != 700)
                        {
                            Pos += 200;
                        }
                        KeyDownFlag = 1;
                    }
                }
                else
                {
                    KeyDownFlag = 0;
                }
                
            }
        }

        
    }

    void Ui::Draw()
    {
        if (TitleScene == 0)
        {
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
            DrawString(700, 700, "音量 ←　10　→", GetColor(255, 255, 255));

            DrawBox(700, Pos, 1200, Pos + 70, GetColor(255, 255, 255), FALSE);
        }
        
    }
}