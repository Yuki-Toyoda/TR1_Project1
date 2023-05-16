#pragma once
#include "MyMath.h"
#include "Map.h"

class MapManager
{

	/// <summary>
	/// コンストラクタ
	/// </summary>
	MapManager();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~MapManager();

	/// <summary>
	/// 初期化処理
	/// </summary>
	static void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	static void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	static void Draw();

	/// <summary>
	/// 指定した座標がマップチップにヒットしているか調べる関数
	/// </summary>
	/// <param name="translate_">調べる座標</param>
	/// <returns>ヒットしているか</returns>
	static bool CheckHitMap(Vector2 translate_);

private:

	

};

