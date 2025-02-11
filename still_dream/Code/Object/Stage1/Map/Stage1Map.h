#pragma once
#include"../../GameObject/GameObject.h"
#include"../../Collision/Collision.h"
#include"../../../JsonMaster/JsonManager/JsonManager.h"
#include"../../StageSelect/StageSelect.h"

#include<DxLib.h>
#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>


namespace dream
{
    

    class Stage1Map : public GameObject
    {
    public:
        struct MapLayer
        {
            int** mapData; // マップチップの2次元配列
            int   mapXNum = 50; // マップチップが横方向に並んでいる数
            int   mapYNum = 10; // マップチップが縦方向に並んでいる数
        };

        /// @brief  コンストラクタ
        Stage1Map();

        /// @brief  デストラクタ
        ~Stage1Map();

        /// @brief  更新処理
        /// @param  デルタタイム
        void Update(const float deltaTime)override;

        /// @brief  描画処理
        void Draw()override;

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

        /// <summary>
        /// マップ後始末
        /// </summary>
        /// <param name ="checkRect">マップと当たっているか調査したい矩形</param>
        /// <returns>マップと衝突したかをtrue/falseで返す</returns>
        static bool mapHitCalc(MapLayer& dst, Collision::sHitRect& checkRect, int scrollCnt);


        MapLayer getMapHitRect() { return layerBrock; };


        
    private:
        static Collision collision;

        static const int mapChipSize = 100;
        static const int mapImgXNum = 2;
        static const int mapImgYNum = 1;

        int scrollcnt;

        MapLayer layerBrock;

        int mapChipImg[64]; //画像ハンドル配列

    };
}