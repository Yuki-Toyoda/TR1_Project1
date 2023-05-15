#include "Object.h"
#include "MyConst.h"

/// <summary>
/// オブジェクト共通の初期化処理
/// 必ずSuccessorInitializeを呼び出す
/// </summary>
void Object::Initialize() {
	// オブジェクト固有の初期化
	SuccessorInitialize();
}
/// <summary>
/// オブジェクト固有の初期化処理
/// </summary>
void Object::SuccessorInitialize() {

	// 中心座標初期化
	translate = { -10000.0f, -10000.0f };
	// 速度初期化
	velocity = { 0.0f, 0.0f };
	// 重力加速度
	GravitationalAcceleration = 0.0f;

	// 生存トリガー初期化
	isAlive = false;
	// 重力トリガー初期化
	enableGravity = false;
	// 当たり判定トリガー初期化
	enableCollision = false;

}

/// <summary>
/// オブジェクト共通の更新処理
/// </summary>
/// <param name="timeScale">ゲーム速度</param>
void Object::Update(const float& timeScale) {
	if (isAlive) {
		
		// オブジェクト固有の更新処理
		SuccessorUpdate(timeScale);

		// 重力が有効なら重力の処理を行う
		if (enableGravity) {
			if (velocity.y < -kVelocityLimit) {
				
			}
			else {
				velocity.y -= (GravitationalAcceleration * timeScale);
			}
		}

		// トンネリング防止
		for (int i = 0; i < 10; i++) {
			// 移動処理
			translate.x += velocity.x * 0.1f * timeScale;
			translate.y += velocity.y * 0.1f * timeScale;

			// 衝突判定
			if (enableCollision) {
				if (translate.y < kFloorHeight) {
					translate.y = kFloorHeight;
				}
			}
		}

		// 衝突判定が有効なら
		if (enableCollision) {
			if (translate.y < kFloorHeight) {
				translate.y = kFloorHeight;
			}
		}
	}
}
/// <summary>
/// オブジェクト固有の更新処理
/// </summary>
/// <param name="timeScale">ゲーム速度</param>
void Object::SuccessorUpdate(const float& timeScale){

}

/// <summary>
/// 描画処理
/// </summary>
void Object::Draw() {
	if (isAlive) {
		
	}
}

/// <summary>
/// オブジェクトのタイプを取得する関数
/// </summary>
/// <returns>オブジェクトのタイプ</returns>
ObjectType Object::GetType() {
	// オブジェクトのタイプを返す
	return TypeObject;
}