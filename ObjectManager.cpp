#include "ObjectManager.h"
#include "MyConst.h"

/// <summary>
/// 全てのオブジェクトをObjectで初期化する処理
/// </summary>
void ObjectManager::Initialize() {

	// ゲーム時間設定
	timeScale = 1.0f;

	for (int i = 0; i < kMaxObjectSize; i++) {
		object[i] = new Object();
		object[i]->Initialize();
	}
}

/// <summary>
/// 全てのオブジェクトを更新する処理
/// </summary>
void ObjectManager::Update() {
	for (int i = 0; i < kMaxObjectSize; i++) {
		if (object[i]->GetType() != TypeObject) {
			object[i]->Update(timeScale);
		}
	}

	CheckAllCollisions();

	// TimeScaleが0以下にならないように
	if (timeScale > kMaxTimeScale) {
		timeScale = kMaxTimeScale;
	}
	if (timeScale < kMinTimeScale) {
		timeScale = kMinTimeScale;
	}

#pragma region Debug

	// TimeScaleを直接いじる
	if (MyInput::GetKeybordState(DIK_I, Press)) {
		timeScale += 0.01f;
	}
	else if (MyInput::GetKeybordState(DIK_K, Press)) {
		if (timeScale > 0.0f) {
			timeScale -= 0.01f;
		}
	}

	if (MyInput::GetKeybordState(DIK_R, Press)) {
		timeScale = 1.0f;
	}

#pragma endregion

}

/// <summary>
/// 全てのオブジェクトを描画する関数
/// </summary>
void ObjectManager::Draw() {
	for (int i = 0; i < kMaxObjectSize; i++) {
		if (object[i]->GetType() != TypeObject) {
			object[i]->Draw(timeScale);
		}
	}

#pragma region Debug

	// タイムスケールの描画
	Novice::ScreenPrintf(0, 20, "timeScale : %4.2f", timeScale);

#pragma endregion

}

#pragma region オブジェクトのインスタンスを作成する関数群

/// <summary>
/// プレイヤーのインスタンスを生成する関数
/// </summary>
/// <param name="translate_">プレイヤーの初期座標</param>
void ObjectManager::MakeNewObjectPlayer(Vector2 translate_) {
	for (int i = 0; i < kMaxObjectSize; i++) {
		// 生成されていれば生成しない
		if (object[i]->GetType() == TypePlayer) {
			break;
		}
		if (!object[i]->GetIsAlive()) {
			object[i] = new Player(translate_);
			object[i]->Initialize();
			break;
		}
	}
}

/// <summary>
/// 敵のインスタンスを生成する関数
/// </summary>
/// <param name="translate_">敵の初期座標</param>
void ObjectManager::MakeNewObjectEnemy(Vector2 translate_) {
	for (int i = 0; i < kMaxObjectSize; i++) {	
		if (!object[i]->GetIsAlive()) {
			object[i] = new Enemy(translate_);
			object[i]->Initialize();
			break;
		}
	}
}

#pragma endregion

#pragma region アクセッサ

/// <summary>
/// 指定したオブジェクトを取得する関数
/// </summary>
/// <param name="objectType">取得するオブジェクトのタイプ</param>
/// <returns></returns>
Object* ObjectManager::GetSelectObject(ObjectType objectType) {
	for (int i = 0; i < kMaxObjectSize; i++) {
		if (object[i]->GetType() == objectType) {
			return object[i];
		}
	}
	return NULL;
}

#pragma endregion

#pragma region TimeScaleを動かす関数

/// <summary>
/// TimeScaleを引数で指定した値にセットする関数
/// </summary>
/// <param name="timeScale_">設定する時間</param>
void ObjectManager::SetTime(float timeScale_) {
	this->timeScale = timeScale_;
}

#pragma endregion

#pragma region 当たり判定

/// <summary>
/// 指定したオブジェクト同士が当たっているかを調べる関数
/// </summary>
/// <param name="object1">調べるオブジェクト1</param>
/// <param name="object2">調べるオブジェクト2</param>
bool ObjectManager::CheckHitObject(Object* object1, Object* object2) {

	// オブジェクト間の当たり判定を検証し、真偽を返す
	return MyMath::CheckHitQuad(object1->GetLeftTop(), object1->GetRightBottom(),
		object2->GetLeftTop(), object2->GetRightBottom());

}

/// <summary>
/// オブジェクト間の当たり判定全てを検知する関数
/// </summary>
void ObjectManager::CheckAllCollisions() {

	Object* player = NULL;
	Object* enemy = NULL;

	// プレイヤーと敵との当たり判定
	for (int i = 0; i < kMaxObjectSize; i++) {
		// プレイヤーを探す
		if (object[i]->GetType() == TypePlayer) {
			// 生存しているか
			if (object[i]->GetIsAlive()) {
				// プレイヤーのオブジェクトを取得
				player = object[i];
			}
		}
	}

	assert(player);

	for (int i = 0; i < kMaxObjectSize; i++) {
		// 敵を探す
		if (object[i]->GetType() == TypeEnemy) {
			// 見つけた敵は生存しているか
			if (object[i]->GetIsAlive()) {
				// 当たっているかを関数で調べる
				if (CheckHitObject(player, object[i])) {
					// プレイヤーに当たった処理を行う
					player->HitObject(TypeEnemy);
				}	
			}
		}
	}

}

#pragma endregion