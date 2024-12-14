#include"Stage1Map.h"

namespace dream
{
    Stage1Map::Stage1Map()
        :GameObject(stage1ObjectTag.MAP)
    {
        LoadDivGraph("Asset/Image/map.png", mapImgXNum * mapImgYNum, mapImgXNum, mapImgYNum, mapChipSize, mapChipSize,mapChipImg);

        //マップ読み込み
        mapLayerLoader(layerBrock, "Asset/Csv/map.csv");
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

    void Stage1Map::Update(float deltaTime)
    {
        Draw();
    }

    void Stage1Map::Draw()
    {
        DrawBox(700, 300, 800, 400, GetColor(255, 255, 255), FALSE);
    }

    void Stage1Map::mapDraw(int scrollOffsetX, int scrollOffsetY)
    {
        mapLayerDraw(layerBrock, scrollOffsetX, scrollOffsetY);
    }

    void Stage1Map::mapLayerDraw(MapLayer& layer, int scrollOffsetX, int scrollOffsetY)
    {
        for (int y = 0; y < layer.mapYNum; y++)
        {
            for (int x = 0; x < layer.mapXNum; x++)
            {
                int imgIndex = layer.mapData[y][x];              // map配列よりブロック種類を取得

                //描画しようとしているidが-1の時は描画をスキップ
                if (imgIndex == -1)
                {
                    continue;
                }

                int imgHandle = mapChipImg[imgIndex];  // indexをつかって画像ハンドル配列から画像ハンドルを取得

                // マップチップ幅でブロック画像を敷き詰めて描画する
                // xは0,1,2・・・と変化する。 x * mapChipSize の計算は 0,64,128,196, ... とブロック幅ごとに増える
                DrawGraph(x * mapChipSize - scrollOffsetX, y * mapChipSize - scrollOffsetY, imgHandle, TRUE);
            }
        }
    }

	bool Stage1Map::mapLayerLoader(MapLayer& dst, const char* mapCSVFileName)
	{
		// dst初期化
		dst.mapData = NULL;
		dst.mapXNum = 0;
		dst.mapYNum = 0;

		// ファイルを開く
        std::ifstream ifs(mapCSVFileName);
        if (!ifs)
        {
            printf("ファイルを開けません");
            return 0;
        }

        char c = 0;
        while (c != '\n')
        {
            //読み取った文字がカンマなら1つカウントを増やす
            ifs >> c;
            if (',' == c)
            {
                dst.mapXNum++;
            }
        }
        dst.mapXNum++;

        //ファイルポインタを先頭に戻し行数を読む
        ifs.seekg(0,std::ios_base::beg);
        bool firstRow = true;
        std::string Len;
        while(ifs>>Len)

        
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
}