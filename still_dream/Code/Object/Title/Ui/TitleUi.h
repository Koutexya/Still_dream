#pragma once
#include"../../GameObject/GameObject.h"
#include"../../StageSelect/StageSelect.h"

namespace dream
{
    class TitleUi : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        TitleUi();

        /// @brief  デストラクタ
        ~TitleUi();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

        /// @brief 入力処理
        void Input()override;

    private:
        int TitleScene = 0; //TitleScene=0でタイトルフェードイン表示　TitleScene=1で選択画面
        bool TitleFlg = true;   //フェードイン表示フラグ
        bool KeySpaceFlag = false;//入力フラグ
        bool KeyUpFlag = false;
        bool KeyDownFlag = false;
        bool KeyLeftFlag = false;
        bool KeyRightFlag = false;
        int Pos = 300;
        int MusicVolume = 100;


        
    };
}