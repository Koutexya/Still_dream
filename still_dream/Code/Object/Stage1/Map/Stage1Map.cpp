#include"Stage1Map.h"

namespace dream
{

    Stage1Map::Stage1Map()
        :GameObject(stage1ObjectTag.MAP)
    {
        scrollcnt = 0;
        //
        auto stageData = JsonManager::StageDataInstance()->StageDataInstance();

        //マップ画像読み込み
        LoadDivGraph(stageData->GetMapImg().c_str(), mapImgXNum * mapImgYNum, mapImgXNum, mapImgYNum, mapChipSize, mapChipSize, mapChipImg);

        //マップ読み込み
        if (stageTag.Stage1 == StageSelect::GetSelect())
        {
            mapLayerLoader(layerBrock, stageData->GetTutorialMapCsv().c_str());
        }
        if (stageTag.Stage2 == StageSelect::GetSelect())
        {
            mapLayerLoader(layerBrock, stageData->GetMapCsv().c_str());
        }

    }

    Stage1Map::~Stage1Map()
    {
        //マップ画像の削除
        for (int i = 0; i < mapImgXNum * mapImgYNum; i++)
        {
            DeleteGraph(mapChipImg[i]);
        }

        mapUnloader(layerBrock);
    }

    void Stage1Map::Update(const float deltaTime)
    {
        if ((mapChipSize * layerBrock.mapXNum - 1980) > scrollcnt)
        {
            scrollcnt += 2;
        }
        else
        {
            StageSelect::SetGameFlag(stageTag.GameClear);
        }
        
    }

    void Stage1Map::Draw()
    {
        mapLayerDraw(layerBrock, scrollcnt, 0);
        if (stageTag.Stage2 == StageSelect::GetSelect())
        {

        }
    }

    void Stage1Map::mapLayerDraw(MapLayer& layer, int scrollOffsetX, int scrollOffsetY)
    {

        for (int y = 0; y < layer.mapYNum; y++)
        {
            for (int x = 0; x < layer.mapXNum; x++)
            {
                int imgIndex = layer.mapData[y][x];              // map配列よりブロック種類を取得
                int imgHandle = mapChipImg[imgIndex];  // indexをつかって画像ハンドル配列から画像ハンドルを取得

                // マップチップ幅でブロック画像を敷き詰めて描画する
                // xは0,1,2・・・と変化する。 x * mapChipSize の計算は 0,100,200, ... とブロック幅ごとに増える
                DrawGraph(x * mapChipSize - scrollOffsetX, y * mapChipSize - scrollOffsetY, imgHandle, TRUE);
            }
        }
    }

	bool Stage1Map::mapLayerLoader(MapLayer& dst, const char* mapCSVFileName)
	{
		// dst初期化
		dst.mapData = NULL;

		// ファイルを開く
        std::ifstream ifs(mapCSVFileName);
        if (!ifs)
        {
            printf("ファイルを開けません");
            return 0;
        }

        ////配列確保
        dst.mapData = new int* [dst.mapYNum];
        int ix, iy;
        for (iy = 0; iy < dst.mapYNum; iy++)
        {
            dst.mapData[iy] = new int[dst.mapXNum];
        }

        std::string Len;
        //ファイルポインタを先頭に戻す
        ifs.seekg(0, std::ios_base::beg);

        //ファイルからデータを配列に移す
        for (iy = 0; iy < dst.mapYNum; iy++)
        {
            //１行読み込み
            std::getline(ifs, Len);
            std::replace(Len.begin(), Len.end(), ',', ' '); //文字列の特定文字を変更
            std::istringstream iss(Len);

            for (ix = 0; ix < dst.mapXNum; ix++)
            {
                iss >> dst.mapData[iy][ix];
            }
        }

        //ファイルを閉じる
        ifs.close();
        
        return true;
	}

	void Stage1Map::mapUnloader(MapLayer& dst)
	{
		// データの解放
		for (int iy = 0; iy < dst.mapYNum; iy++)
		{
			delete[] dst.mapData[iy];
		}
		delete[] dst.mapData;

		// dst初期化
		dst.mapData = NULL;
		dst.mapXNum = 0;
		dst.mapYNum = 0;
	}

    bool Stage1Map::mapHitCalc(MapLayer& dst, Collision::sHitRect& checkRect , int scrollCnt)
    {
        bool hitflg = false;
        Collision::sHitRect blockRect;

        blockRect.w = mapChipSize;
        blockRect.h = mapChipSize;

        // すべてのマップブロック vs 調査ブロックの衝突を調べる
        for (int iy = 0; iy < dst.mapYNum; iy++)
        {
            //マップブロックのY座標
            blockRect.worldLY = static_cast<float>(iy * mapChipSize);
            blockRect.worldRY = static_cast<float>((iy + 1) * mapChipSize);

            for (int ix = 0; ix < dst.mapXNum; ix++)
            {
                // 当たりブロックか 0→通れる 0以外→通れない 
                if (dst.mapData[iy][ix] != 0)
                {
                    // マップブロックのX座標
                    blockRect.worldLX = static_cast<float>(ix * mapChipSize)- scrollCnt;
                    blockRect.worldRX = (ix + 1) * static_cast<float>(mapChipSize)- scrollCnt;
                    // 当たっているか？
                    if (collision.isHitRect(checkRect, blockRect))
                    {
                        // 一度でもブロックと当たったらhitflgをtrueに
                        hitflg = true;
                        //第一引数：キャラクターなどの当たり判定矩形
                        //第二引数：マップなどの固定物の矩形を入れる
                        collision.clacFixHitReactPosition(checkRect, blockRect);
                    }
                }
            }
        }
        return hitflg;
    }

}