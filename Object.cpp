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

	// 座標初期化
	transform.translate = { -100000.0f,-100000.0f };

	// 大きさ初期化
	transform.size = { 0.0f, 0.0f };

	// 倍率
	transform.scale = { 1.0f, 1.0f };

	// 左上
	transform.leftTop = { -transform.size.x / 2.0f, transform.size.y / 2.0f };
	// 右上
	transform.rightTop = { transform.size.x / 2.0f, transform.size.y / 2.0f };
	// 左下
	transform.leftBottom = { -transform.size.x / 2.0f, -transform.size.y / 2.0f };
	// 左上
	transform.rightBottom = { transform.size.x / 2.0f, -transform.size.y / 2.0f };

	// 左上ローカル座標
	transform.kLeftTop = { -transform.size.x / 2.0f, transform.size.y / 2.0f };
	// 右上ローカル座標
	transform.kRightTop = { transform.size.x / 2.0f, transform.size.y / 2.0f };
	// 左下ローカル座標
	transform.kLeftBottom = { -transform.size.x / 2.0f, -transform.size.y / 2.0f };
	// 右下ローカル座標
	transform.kRightBottom = { transform.size.x / 2.0f, -transform.size.y / 2.0f };

	// 速度初期化
	velocity = { 0.0f, 0.0f };

	// 重力加速度初期化
	GravitationalAcceleration = 9.8f / 2.5f;

	// 敵固有のTimeScale
	MyTimeScale = 1.0f;

	// 飛んでいるか
	isFlying = true;
	// 生存トリガーTrue
	isAlive = false;
	// 重力を有効かする
	enableGravity = false;
	// 当たり判定を有効
	enableCollision = false;

}

/// <summary>
/// オブジェクト共通の更新処理
/// </summary>
/// <param name="timeScale">ゲーム速度</param>
void Object::Update(const float& timeScale) {

	if (isAlive) {

		acceleration = { 0,0 };

		// オブジェクト固有の更新処理
		SuccessorUpdate(timeScale);

		// 重力が有効なら重力の処理を行う
		if (enableGravity) {
			if (isFlying) {
				if (velocity.y < -kVelocityLimit) {

				}
				else {
					acceleration.y -= (GravitationalAcceleration * timeScale);
				}
			}
		}

		// 速度に加速度を足す
		velocity = velocity + acceleration;

		// トンネリング防止
		for (int i = 0; i < 10; i++) {
			// 移動処理
			transform.translate.x += velocity.x * 0.1f * timeScale;
			transform.translate.y += velocity.y * 0.1f * timeScale;

			// 衝突判定
			if (enableCollision) {
				if (transform.translate.y < kFloorHeight + (transform.size.y / 2.0f)) {
					transform.translate.y = kFloorHeight + (transform.size.y / 2.0f);
					isFlying = false;
				}
			}
		}

		// 速度を少しずつ減速させる
		if (velocity.x > 0) {
			velocity.x -= 0.25f * timeScale;
			if (velocity.x < 0) {
				velocity.x = 0;
			}
		}
		else if (velocity.x < 0) {
			velocity.x += 0.25f * timeScale;
			if (velocity.x > 0) {
				velocity.x = 0;
			}
		}
		if (velocity.y > 0) {
			velocity.y -= 0.25f * timeScale;
			if (velocity.y < 0) {
				velocity.y = 0;
			}
		}
		else if (velocity.y < 0) {
			velocity.y += 0.25f * timeScale;
			if (velocity.y > 0) {
				velocity.y = 0;
			}
		}

		// 衝突判定が有効なら
		if (enableCollision) {
			if (transform.translate.y < kFloorHeight + (transform.size.y / 2.0f)) {
				transform.translate.y = kFloorHeight + (transform.size.y / 2.0f);
				isFlying = false;
			}
		}

		// アフィン行列生成
		//worldMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);
		worldMatrix = MyMath::MakeAffineMatrix(transform.scale, 0.0f, transform.translate);

		// 行列を合成
		wvpMatrix = MyMath::Multiply(worldMatrix, MyCamera::GetViewMatrix());
		wvpMatrix = MyMath::Multiply(wvpMatrix, MyCamera::GetOrthoMatrix());
		wvpMatrix = MyMath::Multiply(wvpMatrix, MyCamera::GetViewPortMatrix());

		transform.leftTop = MyMath::Transform(transform.kLeftTop, wvpMatrix);
		transform.rightTop = MyMath::Transform(transform.kRightTop, wvpMatrix);
		transform.leftBottom = MyMath::Transform(transform.kLeftBottom, wvpMatrix);
		transform.rightBottom = MyMath::Transform(transform.kRightBottom, wvpMatrix);

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
void Object::Draw(const float& timeScale) {
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

#pragma region 当たり判定

void Object::HitObject(ObjectType objectType) {

}

#pragma endregion