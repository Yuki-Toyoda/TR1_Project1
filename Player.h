﻿#pragma once
#include <Novice.h>
#include "Object.h"
#include "MyMath.h"
#include "MyEnum.h"

class Player : public Object
{

public:

	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="translate_">プレイヤーの初期座標</param>
	Player(Vector2 translate_);

	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();

	/// <summary>
	/// プレイヤーの初期化処理
	/// </summary>
	void SuccessorInitialize() override;

	/// <summary>
	/// オブジェクト共通の更新処理
	/// </summary>
	/// <param name="timeScale">ゲーム時間</param>
	void Update(const float& timeScale) override;

	/// <summary>
	/// プレイヤーの更新処理
	/// </summary>
	/// <param name="timeScale">ゲーム時間</param>
	void  SuccessorUpdate(const float& timeScale) override;

	/// <summary>
	/// 描画処理
	/// </summary>
	/// <param name="timeScale">ゲーム時間</param>
	void Draw(const float& timeScale) override;

	/// <summary>
	/// オブジェクトのタイプを取得する関数
	/// </summary>
	/// <returns>オブジェクトタイプ</returns>
	ObjectType GetType() override;

#pragma region 当たり判定

	/// <summary>
	/// オブジェクトに当たった時に呼び出される関数
	/// </summary>
	/// <param name="objectType">当たったオブジェクトのタイプ</param>
	void HitObject(ObjectType objectType) override;

#pragma endregion

private:

	// テクスチャ
	int textureHandle;

	// カラー
	unsigned int color;

};

