#pragma once
#include "Vector2.h"

/// <summary>
/// トランスフォーム構造体
/// </summary>
struct Transform final{
	Vector2 translate;
	Vector2 leftTop;
	Vector2 rightTop;
	Vector2 leftBottom;
	Vector2 rightBottom;
	Vector2 kLeftTop;
	Vector2 kRightTop;
	Vector2 kLeftBottom;
	Vector2 kRightBottom;
	Vector2 scale;
	Vector2 size;
	float theta;
};
