#pragma once
#include<DxLib.h>
#include<math.h>


///<summary>
//当たり判定短形
///<summary>
struct sHitRect
{
    float w;         //当たり短形幅ピクセル数
    float h;         //当たり短形高さピクセル数
    float worldLX;   //左上X座標
    float worldLY;   //左上Y座標
    float worldRX;   //右上X座標
    float worldRY;   //右上Y座標
};


///<summary>
//当たり初期化
//<param name = "dstRect">初期化したい当たり判定定数</param>
//<param name = "w">当たり判定の幅</param>
//<param name = "h">当たり判定の高さ</param>
///<summary>
void initRect(sHitRect& dstRect, float w, float h);

///<summary>
//当たり判定の移動更新処理
//<param name = "dstRect">初期化したい当たり判定定数</param>
//<param name = "w">当たり判定の幅</param>
//<param name = "h">当たり判定の高さ</param>
///<summary>
void updateWorldRect(sHitRect& dstRect, float x, float y);

///<summary>
//当たり判定短形の描画
//<param name = "rect">描画したい当たり判定短形</param>
///<summary>
void drawRect(const sHitRect& rect);

/// <summary>
/// 二つの矩形が衝突したかを返す
/// </summary>
/// <param name="rect1">矩形1</param>
/// <param name="rect2">矩形2</param>
/// <returns>矩形の二つが衝突したかをtrue/falseで返す</returns>
bool isHitRect(const sHitRect& rect1, const sHitRect& rect2);

/// <summary>
/// 二つの矩形の衝突めり込み量を計算し、mobleRect位置を変更する
/// <summary>
/// <param name="movableRect">移動可能矩形</param>
/// <param name="staticRect">静止矩形(動かないブロックなど)</param>
void clacFixHitReactPosition(sHitRect& movableRect, const sHitRect& staticRect);