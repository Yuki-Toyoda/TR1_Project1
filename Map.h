#pragma once
#include "MyMath.h"
#include "MyEnum.h"
#include "MyCamera.h"

class Map
{
public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Map();
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Map();

	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="type">マップチップの種類</param>
	void Initialize(MapChipType type_);

	/// <summary>
	/// 更新処理
	/// </summary>
	void Update();

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="DrawPosition">描画する座標</param>
	void Draw(Vector2 DrawPosition);


	bool CheckHitBox(Vector2 translate_);

	// マップチップの種類
	MapChipType type;

};

