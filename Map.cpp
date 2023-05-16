#include "Map.h"

/// <summary>
/// コンストラクタ
/// </summary>
Map::Map() {
	Initialize(TypeAir);
}

/// <summary>
/// デストラクタ
/// </summary>
Map::~Map() {

}

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="type_">マップチップの種類</param>
void Map::Initialize(MapChipType type_) {
	this->type = type_;
}

/// <summary>
/// 更新処理
/// </summary>
void Map::Update() {

}

void Map::Draw(Vector2 DrawPosition) {
	switch (type)
	{
	case TypeAir:
		break;
	case TypeNormal:
		

		break;
	default:
		break;
	}
}