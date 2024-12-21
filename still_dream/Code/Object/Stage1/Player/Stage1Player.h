#pragma once
#include<DxLib.h>

#include"../../GameObject/GameObject.h"

namespace dream
{
    class Stage1Player : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Stage1Player();

        /// @brief  デストラクタ
        ~Stage1Player();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

        /// @brief  入力処理
        void Input(float deltaTime)override;

    private:
        POINT mPos;

        const float gravity = 20.0f;    //重力
        const float jumpInitVelocity = 5.5f;    //ジャンプ初速度
        const float jumpUpSpeed = 12.0f;//ジャンプ長押し中上昇速度
        const float jumpButtonAcceptTime = 0.95f;   //ジャンプ長押し受付時間

        int PlayerHandle;   //画像
        float vx, vy;   //速度
        bool jumpFlag;  //ジャンプフラグ
        bool prevJumpButton;    //前フレームでジャンプボタンが押されていたか
        bool isJumpPush;    //ジャンプ押した瞬間か
        bool onGround;  //接地ふらぐ
        float jumpTimer;    //ジャンプ長押し時間タイマー
    };
}