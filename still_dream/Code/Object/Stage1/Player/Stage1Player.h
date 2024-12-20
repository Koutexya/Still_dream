#pragma once
#include<DxLib.h>
#include<vector>

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
        void Input()override;

    private:
        VECTOR mPos;

        const float gravity = 20.0f;    //重力
        const float jumpInitVelocity = 5.5f;    //ジャンプ初速度


        int PlayerHandle;   //画像
        float vx, vy;   //速度
        bool jumpFlag;  //ジャンプフラグ
        bool prevJumpButton;    //前フレームでジャンプボタンが押されていたか
        bool isJumpPush;    //ジャンプ押した瞬間か
        bool onGround;  //接地ふらぐ
    };
}