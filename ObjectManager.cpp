#include "ObjectManager.h"

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
}

/// <summary>
/// 全てのオブジェクトを描画する関数
/// </summary>
void ObjectManager::Draw() {
	for (int i = 0; i < kMaxObjectSize; i++) {
		if (object[i]->GetType() != TypeObject) {
			object[i]->Draw();
		}
	}
}

#pragma region オブジェクトのインスタンスを作成する関数群



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
