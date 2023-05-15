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
	void Initialize(Vector2 translate_);

	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="translate_">カメラ中心座標</param>
	void Update(Vector2 translate_);

#pragma region アクセッサ

	/// <summary>
	/// カメラの座標をセットする関数
	/// </summary>
	/// <param name="translate_"></param>
	void SetTranslate(const Vector2& translate_) { this->translate = translate_; }

	/// <summary>
	/// カメラの切り抜き範囲を設定する関数
	/// </summary>
	/// <param name="clipLeftTop_">切り抜き範囲左上</param>
	/// <param name="clipRightBottom_">切り抜き範囲右下</param>
	/// <param name="viewPortLeftTop_">表示範囲左上</param>
	/// <param name="viewPortRightBottom_">表示範囲右下</param>
	void SetUpCamera(const Vector2& clipLeftTop_, const Vector2& clipRightBottom_, const Vector2& viewPortLeftTop_, const Vector2& viewPortRightBottom_);

	/// <summary>
	/// カメラの変換後行列を取得する関数
	/// </summary>
	/// <returns>変換後行列</returns>
	Matrix3x3 GetvpvpMatrix() { return vpvpMatrix; }

#pragma endregion


private:

	// カメラ座標
	Vector2 translate;
	// カメラ倍率
	Vector2 scale;

	// 切り抜き範囲左上
	Vector2 orthoLeftTop;
	// 切り抜き範囲右下
	Vector2 orthoRightBottom;

	// 表示範囲左上
	Vector2 viewPortLeftTop;
	// 表示範囲右下
	Vector2 viewPortRightBottom;

	// カメラ行列
	Matrix3x3 cameraMatrix;
	// ビュー行列
	Matrix3x3 viewMatrix;
	// 正射影行列
	Matrix3x3 orthoMatrix;
	// ビューポート行列
	Matrix3x3 viewPortMatrix;
	// 変換後行列
	Matrix3x3 vpvpMatrix;


};

