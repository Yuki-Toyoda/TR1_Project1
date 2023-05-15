#include "Player.h"
#include "MyConst.h"

/// <summary>
/// コンストラクタ
/// </summary>
/// <param name="translate_">プレイヤーの初期座標</param>
Player::Player(Vector2 translate_) {
	// 引数の値をメンバ変数に代入
	this->translate = translate_;
}

/// <summary>
/// デストラクタ
/// </summary>
Player::~Player() {

}

/// <summary>
/// プレイヤーの初期化処理
/// </summary>
void Player::SuccessorInitialize() {

	// 大きさ初期化
	size = { 50.0f, 100.0f };

	// 倍率
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
	kLeftTop = { -size.x / 2.0f, size.y / 2.0f };
	// 右上ローカル座標
	kRightTop = { size.x / 2.0f, size.y / 2.0f };
	// 左下ローカル座標
	kLeftBottom = { -size.x / 2.0f, -size.y / 2.0f };
	// 右下ローカル座標
	kRightBottom = { size.x / 2.0f, -size.y / 2.0f };

	// 速度初期化
	velocity = { 0.0f, 0.0f };

	// 重力加速度初期化
	GravitationalAcceleration = 9.8f;

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
/// オブジェクト共通の更新処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Player::Update(const float& timeScale) {
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
/// プレイヤーの更新処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Player::SuccessorUpdate(const float& timeScale) {

	// 移動処理
	if (MyInput::GetKeybordState(DIK_D, Press)) {
		velocity.x = 5.0f;
	}
	else if (MyInput::GetKeybordState(DIK_A, Press)) {
		velocity.x = -5.0f;
	}

	if (MyInput::GetKeybordState(DIK_W, Press)) {
		velocity.y = 5.0f;
	}
	else if (MyInput::GetKeybordState(DIK_S, Press)) {
		velocity.y = -5.0f;
	}

}

/// <summary>
/// プレイヤーの描画処理
/// </summary>
/// <param name="timeScale">ゲーム時間</param>
void Player::Draw(const float& timeScale) {

	Novice::ScreenPrintf(0, 0, "leftTop : x = %4.2f y = %4.2f", leftTop.x, leftTop.y);
	Novice::ScreenPrintf(0, 20, "rightTop : x = %4.2f y = %4.2f", rightTop.x, rightTop.y);
	Novice::ScreenPrintf(0, 40, "leftBottom : x = %4.2f y = %4.2f", leftBottom.x, leftBottom.y);
	Novice::ScreenPrintf(0, 60, "rightBottom : x = %4.2f y = %4.2f", rightBottom.x, rightBottom.y);

	if (isAlive) {
		Novice::DrawQuad(
			(int)leftTop.x, (int)leftTop.y,
			(int)rightTop.x, (int)rightTop.y,
			(int)leftBottom.x, (int)leftBottom.y,
			(int)rightBottom.x, (int)rightBottom.y,
			0, 0,
			1, 1,
			textureHandle,
			BLACK
		);

		/*Novice::DrawQuad(
			(int)translate.x - (int)size.x / 2, (int)translate.y - (int)size.y / 2,
			(int)translate.x + (int)size.x / 2, (int)translate.y - (int)size.y / 2,
			(int)translate.x - (int)size.x / 2, (int)translate.y + (int)size.y / 2,
			(int)translate.x + (int)size.x / 2, (int)translate.y + (int)size.y / 2,
			0, 0,
			1, 1,
			textureHandle,
			WHITE
		);*/

	}

}

/// <summary>
/// オブジェクトのタイプを取得する関数
/// </summary>
/// <returns>オブジェクトタイプ</returns>
ObjectType Player::GetType() {
	return TypePlayer;
}
