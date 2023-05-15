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
	//translate = { -10000.0f, -10000.0f };
	translate = { 640.0f, 360.0f };

	// 速度初期化
	velocity = { 0.0f, 0.0f };
	// 大きさ初期化
	size = { 0.0f, 0.0f };
	// 倍率初期化
	scale = { 1.0f, 1.0f };

	// 左上
	leftTop = { -size.x / 2.0f, size.y / 2.0f };
	// 右上
	rightTop = { size.x / 2.0f, size.y / 2.0f };
	// 左下
	leftBottom = { -size.x / 2.0f, -size.y / 2.0f };
	// 左上
	rightBottom = { size.x / 2.0f, -size.y / 2.0f };

	// 左上ローカル座標
	Vector2 kLeftTop = { -size.x / 2.0f, size.y / 2.0f };
	// 右上ローカル座標
	Vector2 kRightTop = { size.x / 2.0f, size.y / 2.0f };
	// 左下ローカル座標
	Vector2 kLeftBottom = { -size.x / 2.0f, -size.y / 2.0f };
	// 右下ローカル座標
	Vector2 kRightBottom = { size.x / 2.0f, -size.y / 2.0f };

	// 重力加速度
	GravitationalAcceleration = 0.0f;

	// 生存トリガー初期化
	isAlive = true;
	// 空中にいる
	isFlying = true;
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

		// 速度初期化
		velocity = { 0,0 };

		// オブジェクト固有の更新処理
		SuccessorUpdate(timeScale);

		// 重力が有効なら重力の処理を行う
		if (enableGravity) {
			if (isFlying) {
				if (velocity.y < -kVelocityLimit) {

				}
				else {
					velocity.y -= (GravitationalAcceleration * timeScale);
				}
			}
			else {
				velocity.y = 0.0f;
			}
		}

		// トンネリング防止
		for (int i = 0; i < 10; i++) {
			// 移動処理
			translate.x += velocity.x * 0.1f * timeScale;
			translate.y += velocity.y * 0.1f * timeScale;

			// 衝突判定
			if (enableCollision) {
				if (translate.y < kFloorHeight + (size.y / 2.0f)) {
					translate.y = kFloorHeight + (size.y / 2.0f);
					isFlying = false;
				}
			}
		}

		// 衝突判定が有効なら
		if (enableCollision) {
			if (translate.y < kFloorHeight + (size.y / 2.0f)) {
				translate.y = kFloorHeight + (size.y / 2.0f);
				isFlying = false;
			}
		}

		// アフィン行列生成
		worldMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);

		// 行列を合成
		wvpMatrix = MyMath::Multiply(worldMatrix, MyCamera::GetViewMatrix());
		wvpMatrix = MyMath::Multiply(wvpMatrix, MyCamera::GetOrthoMatrix());
		wvpMatrix = MyMath::Multiply(wvpMatrix, MyCamera::GetViewPortMatrix());

		// 合成した行列で4頂点を変換する
		leftTop = MyMath::Transform(kLeftTop, wvpMatrix);
		rightTop = MyMath::Transform(kRightTop, wvpMatrix);
		leftBottom = MyMath::Transform(kLeftBottom, wvpMatrix);
		rightBottom = MyMath::Transform(kRightBottom, wvpMatrix);

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
		Novice::DrawBox((int)translate.x, (int)translate.y,
			(int)size.x, (int)size.y,
			0.0f,
			WHITE,
			kFillModeSolid);
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