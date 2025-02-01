#pragma once
#include<DxLib.h>

#include"../../GameObject/GameObject.h"
#include"../../Collision/Collision.h"
#include"../Map/Stage1Map.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"
#include"../../StageSelect/StageSelect.h"

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

        /// <summary>
        /// 当たり判定矩形からプレイヤー位置を修正する
        /// </summary>
        /// <param name="hitRect">当たり判定矩形</param>
        void playerfixColPosition(Collision::sHitRect& hitRect);

        ///@brief   プレイヤーの当たり判定矩形を返す
        ///@return  プレイヤーの当たり判定矩形
        Collision::sHitRect getPlayerHitRect();

        ///@brief   地面に立っているか
        ///@param   足元の当たり判定結果
        void playerSetGroundFlg(bool groundFlg);

        ///@brief   頭を壁にぶつけたか
        ///@param   頭の当たり判定結果
        void playerSetHeadHitFlg(bool headHitFlg);


        ///@brief   プレイヤーの足元コライダーのゲット
        ///@return  足元コライダーの矩形情報
        Collision::sHitRect playerGetGroundCollider();

        ///@brief   プレイヤーの頭上コライダーのゲット
        ///@return  頭上コライダーの矩形情報
        Collision::sHitRect playerGetHeadCollider();

    private:
        Stage1Map stage1;

        POINT mPos;
        Collision::sHitRect playerHit; //プレイヤー当たり判定
        Collision::sHitRect playerFootCollider;    //接地コライダー
        Collision::sHitRect playerHeadCollider;    //頭上コライダー
        Collision::sHitRect playerRightCollider;   //右側コライダー

        const float gravity = 40.0f;    //重力
        const float jumpInitVelocity = 80.0f;    //ジャンプ初速度

        int PlayerHandle;   //画像
        float vx, vy;   //速度
        bool jumpFlag;  //ジャンプフラグ
        bool prevJumpButton;    //前フレームでジャンプボタンが押されていたか
        bool isJumpPush;    //ジャンプ押した瞬間か
        bool onGround;  //接地しているか
        bool hitHead;   //頭がぶつかったか
        bool firstmPos;
        int scrollCnt;
        
        
    };
}