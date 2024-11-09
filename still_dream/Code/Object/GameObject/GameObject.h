#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_

#include<DxLib.h>
#include<string>

#include"../../JsonMaster/JsonManager/JsonManager.h"

namespace dream
{
    /// @brief  ゲームオブジェクトの基底クラス
    class GameObject
    {
    public:
        /// @brief  コンストラクタ
        /// @param  tagName=オブジェクト名
        GameObject(std::string tagName);

        /// @brief  デストラクタ
        virtual ~GameObject();

        /// @brief  更新
        /// @param  deltaTime=デルタタイム
        virtual void Update(float deltaTime) = 0;

        /// @brief  描画
        virtual void Draw() = 0;

        /// @brief  操作処理
        virtual void Input() {};

        /// @brief  動き処理
        /// @param  KeyType=入力されたキー
        virtual void Move(int KeyType) {};

        /// @brief  タグ名取得
        /// @return タグ名
        std::string GetTagName()const { return mTag; }

        /// @brief  座標取得
        /// @return オブジェクトの位置
        const VECTOR& GetObjPos()const { return mPos; }



    private:
        VECTOR mPos;    //オブジェクト位置
        std::string mTag;   //オブジェクト種類
    };
}



#endif _GAMEOBJECT_H_
