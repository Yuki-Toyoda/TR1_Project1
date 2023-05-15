#pragma once
#include "MyMath.h"

/// <summary>
/// カメラ　中心座標にを設定する
/// </summary>
class MyCamera
{
public:

	/// <summary>
	/// 初期化処理
	/// </summary>
	/// <param name="translate_">カメラ中心座標</param>
	static void Initialize(Vector2 translate_);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="translate_">カメラ中心座標</param>
	static void Update(Vector2 translate_);

#pragma region アクセッサ

	/// <summary>
	/// カメラの座標をセットする関数
	/// </summary>
	/// <param name="translate_"></param>
	static void SetTranslate(const Vector2& translate_);

	/// <summary>
	/// カメラの切り抜き範囲を設定する関数
	/// </summary>
	/// <param name="clipLeftTop_">切り抜き範囲左上</param>
	/// <param name="clipRightBottom_">切り抜き範囲右下</param>
	/// <param name="viewPortLeftTop_">表示範囲左上</param>
	/// <param name="viewPortRightBottom_">表示範囲右下</param>
	static void SetUpCamera(const Vector2& clipLeftTop_, const Vector2& clipRightBottom_, const Vector2& viewPortLeftTop_, const Vector2& viewPortRightBottom_);

	/// <summary>
	/// ビュー行列を取得する関数
	/// </summary>
	/// <returns>ビュー行列</returns>
	static Matrix3x3 GetViewMatrix();

	/// <summary>
	/// 正射影行列を取得する関数
	/// </summary>
	/// <returns>正射影行列</returns>
	static Matrix3x3 GetOrthoMatrix();

	/// <summary>
	/// ビューポート行列を取得する関数
	/// </summary>
	/// <returns>ビューポート行列</returns>
	static Matrix3x3 GetViewPortMatrix();

#pragma endregion


private:

	// カメラ座標
	static Vector2 translate;
	// カメラ倍率
	static Vector2 scale;

	// 切り抜き範囲左上
	static Vector2 orthoLeftTop;
	// 切り抜き範囲右下
	static Vector2 orthoRightBottom;

	// 表示範囲左上
	static Vector2 viewPortLeftTop;
	// 表示範囲右下
	static Vector2 viewPortRightBottom;

	// カメラ行列
	static Matrix3x3 cameraMatrix;
	// ビュー行列
	static Matrix3x3 viewMatrix;
	// 正射影行列
	static Matrix3x3 orthoMatrix;
	// ビューポート行列
	static Matrix3x3 viewPortMatrix;


};

