#pragma once


namespace dream
{
    /// @brief  Fpsクラス
    class Fps
    {
    public:
        /// @brief  コンストラクタ
        Fps();

        /// @brief  デストラクタ
        ~Fps();

        /// @brief  更新処理
        void Update();

        /// @brief  デルタタイム取得
        /// @return デルタタイム
        float GetDeltaTime()const { return deltaTime; }

    private:
        float nowTime;  //現在の時間
        float prevTime; //過去の時間
        float deltaTime;    //デルタタイム;
    };
}