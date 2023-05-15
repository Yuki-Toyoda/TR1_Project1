#pragma once
#include "MyEnum.h"
#include "MyMath.h"

/// <summary>
/// キー入力検知クラス
/// </summary>
class MyInput
{
public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	static void Initialize();

	/// <summary>
	/// 更新処理
	/// </summary>
	static void Update();

	/// <summary>
	/// マウス座標取得
	/// </summary>
	/// <returns>マウス座標</returns>
	static Vector2 GetMousePosition();

	/// <summary>
	/// マウス入力状態検知
	/// </summary>
	/// <param name="key">入力状態</param>
	/// <param name="state">入力状態</param>
	/// <returns>真偽</returns>
	static bool GetMouseState(MouseButton key, InputState state);

	/// <summary>
	/// キー入力状態検知
	/// </summary>
	/// <param name="key">検知するキー</param>
	/// <param name="state">入力状態</param>
	/// <returns>真偽</returns>
	static bool GetKeybordState(int key, InputState state);

private:

	// マウス座標
	static Vector2 mousePosition;

	// キー入力状態
	static char keys[];
	// 前フレームのキー入力状態
	static char preKeys[];

};

