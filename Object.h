#pragma once
#include <Novice.h>
#include "MyInput.h"
#include "MyMath.h"
#include "MyEnum.h"

/// <summary>
/// 時間に影響される全ての物を管理するクラス
/// </summary>
class Object
{
	
public:

#pragma region Initialize

	/// <summary>
	/// オブジェクト共通の初期化処理
	/// 必ずSuccessorInitializeを呼び出す
	/// </summary>
	virtual void Initialize();
	/// <summary>
	/// オブジェクト固有の初期化処理
	/// </summary>
	virtual void SuccessorInitialize();

	/// <summary>
	/// オブジェクト共通の更新処理
	/// </summary>
	/// <param name="timeScale">ゲーム速度</param>
	virtual void Update(const float& timeScale);
	/// <summary>
	/// オブジェクト固有の更新処理
	/// </summary>
	/// <param name="timeScale">ゲーム速度</param>
	virtual void SuccessorUpdate(const float& timeScale);

	/// <summary>
	/// 描画処理
	/// </summary>
	virtual void Draw();

#pragma endregion

#pragma region アクセッサ

	/// <summary>
	/// オブジェクトの中心座標を取得するゲッター
	/// </summary>
	Vector2 GetTranslate() { return translate; }

	/// <summary>
	/// オブジェクトの移動速度を取得するゲッター
	/// </summary>
	/// <returns></returns>
	Vector2 GetVelocity() { return velocity; }

	/// <summary>
	/// オブジェクトの生存状態を検知するゲッター
	/// </summary>
	/// <returns></returns>
	bool GetIsAlive() { return isAlive; }

	/// <summary>
	/// オブジェクトの座標のセッター
	/// </summary>
	/// <param name="translate">位置座標</param>
	void SetTranslate(Vector2 translate_) { this->translate = translate_; }

	/// <summary>
	/// オブジェクトの速度のセッター
	/// </summary>
	/// <param name="velocity">速度</param>
	void SetVelocity(Vector2 velocity_) { this->velocity = velocity_; }

	/// <summary>
	/// オブジェクトの生存状態のセッター
	/// </summary>
	/// <param name="isAlive">生存状態</param>
	void SetIsAlive(bool isAlive_) { this->isAlive = isAlive_; }

	/// <summary>
	/// オブジェクトの重力を有効（無効）にするセッター
	/// </summary>
	/// <param name="enableGravity">重力を有効、無効</param>
	void SetEnableGravity(bool enableGravity_) { this->enableGravity = enableGravity_; }

	/// <summary>
	/// オブジェクトの当たり判定を有効（無効）にするセッター
	/// </summary>
	/// <param name="enableCollision">当たり判定を有効（無効）</param>
	void SetEnableCollison(bool enableCollision_) { this->enableCollision = enableCollision_; }

	/// <summary>
	/// オブジェクトのタイプを取得する関数
	/// </summary>
	/// <returns>オブジェクトのタイプ</returns>
	virtual ObjectType GetType();

#pragma endregion

protected:

	/// メンバ変数

	// 中心座標
	Vector2 translate;
	// 速度
	Vector2 velocity;

	// 重力加速度
	float GravitationalAcceleration;

	// 生存トリガー
	bool isAlive;

	// 重力を有効にするか
	bool enableGravity;

	// 当たり判定を有効にするか
	bool enableCollision;

};

