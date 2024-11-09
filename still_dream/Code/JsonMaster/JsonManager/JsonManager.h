#pragma once
#include<memory>


namespace dream
{
    /// @brief  Jsonデータ管理クラス
    class JsonManager final
    {
    public:
        /// @brief  デストラクタ
        ~JsonManager();

        /// @brief  初期化
        static void InitJsonManager();

    private:
        /// @brief  コンストラクタ
        JsonManager();

        static std::unique_ptr<class JsonManager> jsonmanager;  //自身の実態
    };
}