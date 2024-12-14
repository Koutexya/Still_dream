#pragma once
#include"../../GameObject/GameObject.h"

#include<DxLib.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>


namespace dream
{
    struct MapLayer
    {
        int** mapData; // マップチップの2次元配列
        int   mapXNum; // マップチップが横方向に並んでいる数
        int   mapYNum; // マップチップが縦方向に並んでいる数
    };

    class Stage1Map : public GameObject
    {
    public:
        /// @brief  コンストラクタ
        Stage1Map();

        /// @brief  デストラクタ
        ~Stage1Map();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

        /// @brief  マップ描画
        void mapDraw(int scrollOffsetX, int scrollOffsetY);

        /// @brief マップローダー
        /// @param dst 初期化したいマップデータ
        /// @param mapCSVFileName マップファイル名
        /// @return 読み込みに成功したかどうか(true,false)
        bool mapLayerLoader(MapLayer& dst, const char* mapCSVFileName);

        /// @brief マップの破棄
        /// @param dst メモリ開放したいマップデータ
        void mapUnloader(MapLayer& dst);

        /// @brief マップのレイヤーを描画
        /// @param layer 描画したいレイヤー
        void mapLayerDraw(MapLayer& layer, int scrollOffsetX, int scrollOffsetY);

    private:

        const int mapChipSize = 100;
        const int mapImgXNum = 2;
        const int mapImgYNum = 1;

        MapLayer layerBrock;

        int mapChipImg[64]; //画像ハンドル配列

    };
}