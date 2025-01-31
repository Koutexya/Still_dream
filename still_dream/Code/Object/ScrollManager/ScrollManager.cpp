#include"ScrollManager.h"

namespace dream
{
	void ScrollManager::ScrollManagerInit(int screenwidth, int screenheight, const Collision::sHitRect& worldRect)
	{
		screenWidth = screenwidth;
		screenHeight = screenheight;

		screenXMax = screenWidth / 12.0f * 3.0f;      // スクリーン横幅 3/12 の位置を超えたら右スクロール開始 
		screenYMin = screenHeight / 12.0f * 3.0f;      // スクリーン縦幅 3/12 の位置を超えたら上スクロール開始
		screenYMax = screenHeight / 12.0f * 6.0f;      // スクリーン縦幅 6/12 の位置を超えたら下スクロール開始

		scrollXMax = worldRect.worldRX - screenWidth;  // 最大右方向スクロール量 
		scrollYMin = worldRect.worldLY;                // 最小上方向スクロール量
		scrollYMax = worldRect.worldRY - screenHeight; // 最大下方向スクロール量

	}

	void ScrollManager::ScrollUpdate(const Collision::sHitRect& playerRect, float deltaTime)
	{
		dx = dy = 0.0f;
		// プレイヤーがスクロール境界を超えていたら右スクロール量を計算する
		if (playerRect.worldRX > scrollX + screenXMax)
		{
			dx = playerRect.worldRX - (scrollX + screenXMax);
		}

		// 上スクロール
		if (playerRect.worldLY < scrollY + screenYMin)
		{
			dy = playerRect.worldLY - (scrollY + screenYMin);
		}

		//　下スクロール
		if (playerRect.worldRY > scrollY + screenYMax)
		{
			dy = playerRect.worldRY - (scrollY + screenYMax);
		}

		// 現在の矩形位置を変更する
		scrollX += dx;
		scrollY += dy;

		// スクロール量が最大・最小量を超えていたら範囲内に収める
		if (scrollX > scrollXMax)
		{
			scrollX = scrollXMax;
		}

		if (scrollY > scrollYMax)
		{
			scrollY = scrollYMax;
		}

		if (scrollY < scrollYMin)
		{
			scrollY = scrollYMin;
		}

	}

	int ScrollManager::ScrollGetDrawOffsetX()
	{
		return static_cast<int>(scrollX);
	}

	int ScrollManager::ScrollGetDrawOffsetY()
	{
		return static_cast<int>(scrollY);
	}

	void ScrollManager::ScrollDebugShow()
	{
		// スクロール境界線の描画
		DrawLine((int)screenXMax, 0, (int)screenXMax, (int)screenHeight, GetColor(255, 255, 0));
		DrawLine(0, (int)screenYMin, (int)screenWidth, (int)screenYMin, GetColor(255, 255, 0));
		DrawLine(0, (int)screenYMax, (int)screenWidth, (int)screenYMax, GetColor(255, 255, 0));
	}

	Collision::sHitRect ScrollManager::GetPlayArea()
	{
		// 現在のスクロールのワールド座標を計算する
		// 画面4隅のワールド座標を矩形化する
		Collision::sHitRect rect;
		rect.worldLX = scrollX;
		rect.worldLY = scrollY;
		rect.worldRX = scrollX + screenWidth;
		rect.worldRY = scrollY + screenHeight;

		return rect;
	}
}