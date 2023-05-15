#include <Novice.h>
#include "MyInput.h"

/// <summary>
/// 初期化処理
/// </summary>
void MyInput::Initialize() {

	// マウス座標初期化
	mousePosition = { 0.0f, 0.0f };

	// キー入力状態の初期化
	for (int i = 0; i < 256; i++) {
		keys[i] = { 0 };
		preKeys[i] = { 0 };
	}

}

/// <summary>
/// 更新処理
/// </summary>
void MyInput::Update() {

	// マウス位置を取得する
	int x = 0; int y = 0;
	Novice::GetMousePosition(&x, &y);
	mousePosition = { (float)x, (float)y };

	// キー情報取得
	memcpy(preKeys, keys, 256);
	Novice::GetHitKeyStateAll(keys);

}

/// <summary>
/// マウス座標取得
/// </summary>
/// <returns>マウス座標</returns>
Vector2 MyInput::GetMousePosition() {
	return mousePosition;
}

/// <summary>
/// マウス入力状態検知
/// </summary>
/// <param name="key">入力状態</param>
/// <param name="state">入力状態</param>
/// <returns>真偽</returns>
bool MyInput::GetMouseState(MouseButton key, InputState state) {
	switch (state)
	{
	case Null:
		// 押されていない場合
		if (!Novice::IsTriggerMouse(key)) {
			return true;
		}
		else {
			return false;
		}
	case Trigger:
		// 押された瞬間
		if (Novice::IsTriggerMouse(key)) {
			return true;
		}
		else {
			return false;
		}
	case Press:
		// 押している間
		if (Novice::IsPressMouse(key)) {
			return true;
		}
		else {
			return false;
		}
	default:
		// 上記以外の場合はエラー
		return false;
	}
}

/// <summary>
/// キー入力状態検知
/// </summary>
/// <param name="key">検知するキー</param>
/// <param name="state">入力状態</param>
/// <returns>真偽</returns>
bool MyInput::GetKeybordState(int key, InputState state) {
	switch (state)
	{
	case Null:
		//押されていない場合
		if (!keys[key] && !preKeys[key]) {
			return true;
		}
		else {
			return false;
		}

	case Trigger:
		//押した瞬間
		if (keys[key] && !preKeys[key]) {
			return true;
		}
		else {
			return false;
		}

	case Press:
		//押している間
		if (keys[key]) {
			return true;
		}
		else {
			return false;
		}

	default:
		//上記以外だった場合はエラー
		return false;
	}
}


/// 変数実態宣言
// マウス座標
Vector2 MyInput::mousePosition;

// キー入力状況
char MyInput::keys[256];

// 前フレームでの入力状況
char MyInput::preKeys[256];
