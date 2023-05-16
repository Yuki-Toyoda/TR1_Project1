#include "Enemy.h"
#include "MyConst.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="translate_">敵の初期座標</param>
Enemy::Enemy(Vector2 translate_) {
	// 引数の値をメンバ変数に代入する
	transform.translate = translate_;
}

/// <summary>
/// デストラクタ
/// </summary>
Enemy::~Enemy() {

}

/// <summary>
/// 初期化処理
/// </summary>
void Enemy::SuccessorInitialize() {

	// 大きさ初期化
	transform.size = { 50.0f, 100.0f };

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
	isAlive = true;
	// 重力を有効かする
	enableGravity = true;
	// 当たり判定を有効
	enableCollision = true;

	// テクスチャ読み込み
	textureHandle = Novice::LoadTexture("white1x1.png");

}

/// <summary>
/// 敵の更新処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Enemy::Update(const float& timeScale) {
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
/// 敵固有の更新処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Enemy::SuccessorUpdate(const float& timeScale) {

	if (MyInput::GetKeybordState(DIK_T, Press)) {
		transform.translate.x = 0.0f;
	}

	velocity.x = 1.0f * timeScale;

}

/// <summary>
/// 敵の描画処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Enemy::Draw(const float& timeScale) {
	if (isAlive) {
		Novice::DrawQuad(
			(int)transform.leftTop.x, (int)transform.leftTop.y,
			(int)transform.rightTop.x, (int)transform.rightTop.y,
			(int)transform.leftBottom.x, (int)transform.leftBottom.y,
			(int)transform.rightBottom.x, (int)transform.rightBottom.y,
			0, 0,
			1, 1,
			textureHandle,
			RED
		);
	}
}

/// <summary>
/// オブジェクトのタイプを取得する関数
/// </summary>
/// <returns>オブジェクトタイプ</returns>
ObjectType Enemy::GetType() {
	return TypeEnemy;
}

/// <summary>
/// オブジェクトに当たった時に呼び出される関数
/// </summary>
/// <param name="objectType">当たったオブジェクトのタイプ</param>
void Enemy::HitObject(ObjectType objectType) {
	
}