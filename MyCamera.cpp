#include "MyCamera.h"
#include "MyConst.h"

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="translate_">カメラ中心座標</param>
void MyCamera::Initialize(Vector2 translate_) {

	// 引数の値をメンバ変数に代入
	translate = translate_;
	// カメラの拡大率初期化
	scale = { 1.0f, 1.0f };

	// カメラの設定
	SetUpCamera({ -(float)kWindowWidth / 2, (float)kWindowHeight / 2 }, 
		{ (float)kWindowWidth / 2, -(float)kWindowHeight / 2 }, 
		{ 0.0f, 0.0f }, 
		{ (float)kWindowWidth, (float)kWindowHeight });

	// カメラ行列生成
	cameraMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);
	// ビュー行列に変換する
	viewMatrix = MyMath::Inverse(cameraMatrix);

	// 正射影行列生成
	orthoMatrix = MyMath::MakeOrthGraphicMatrix(orthoLeftTop.x, orthoLeftTop.y, orthoRightBottom.x, orthoRightBottom.y);
	// ビューポート行列生成
	viewPortMatrix = MyMath::MakeViewportMatrix(viewPortLeftTop.x, viewPortLeftTop.y, viewPortRightBottom.x, viewPortRightBottom.y);

}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="translate_">カメラ中心座標</param>
void MyCamera::Update(Vector2 translate_) {

	// 引数の値をメンバ変数に代入
	translate = translate_;

	// カメラ行列生成
	cameraMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);
	// ビュー行列に変換する
	viewMatrix = MyMath::Inverse(cameraMatrix);

	// 正射影行列生成
	orthoMatrix = MyMath::MakeOrthGraphicMatrix(orthoLeftTop.x, orthoLeftTop.y, orthoRightBottom.x, orthoRightBottom.y);
	// ビューポート行列生成
	viewPortMatrix = MyMath::MakeViewportMatrix(viewPortLeftTop.x, viewPortLeftTop.y, viewPortRightBottom.x, viewPortRightBottom.y);

}

/// <summary>
/// カメラの座標をセットする関数
/// </summary>
/// <param name="translate_"></param>
void MyCamera::SetTranslate(const Vector2& translate_) {
	// 引数の値をメンバ変数に代入
	translate = translate_;
}

/// <summary>
/// カメラの切り抜き範囲を設定する関数
/// </summary>
/// <param name="clipLeftTop_">切り抜き範囲左上</param>
/// <param name="clipRightBottom_">切り抜き範囲右下</param>
/// <param name="viewPortLeftTop_">表示範囲左上</param>
/// <param name="viewPortRightBottom_">表示範囲右下</param>
void MyCamera::SetUpCamera(const Vector2& clipLeftTop_, const Vector2& clipRightBottom_, const Vector2& viewPortLeftTop_, const Vector2& viewPortRightBottom_) {

	// 引数の値をメンバ変数に代入
	orthoLeftTop = clipLeftTop_;
	orthoRightBottom = clipRightBottom_;
	viewPortLeftTop  = viewPortLeftTop_;
	viewPortRightBottom = viewPortRightBottom_;

}

/// <summary>
/// ビュー行列を取得する関数
/// </summary>
/// <returns>ビュー行列</returns>
Matrix3x3 MyCamera::GetViewMatrix() {
	return viewMatrix;
}

/// <summary>
/// 正射影行列を取得する関数
/// </summary>
/// <returns>正射影行列</returns>
Matrix3x3 MyCamera::GetOrthoMatrix() {
	return orthoMatrix;
}

/// <summary>
/// ビューポート行列を取得する関数
/// </summary>
/// <returns>ビューポート行列</returns>
Matrix3x3 MyCamera::GetViewPortMatrix() {
	return viewPortMatrix;
}

// カメラ座標
Vector2 MyCamera::translate;
// カメラ倍率
Vector2 MyCamera::scale;

// 切り抜き範囲左上
Vector2 MyCamera::orthoLeftTop;
// 切り抜き範囲右下
Vector2 MyCamera::orthoRightBottom;

// 表示範囲左上
Vector2 MyCamera::viewPortLeftTop;
// 表示範囲右下
Vector2 MyCamera::viewPortRightBottom;

// カメラ行列
Matrix3x3 MyCamera::cameraMatrix;
// ビュー行列
Matrix3x3 MyCamera::viewMatrix;
// 正射影行列
Matrix3x3 MyCamera::orthoMatrix;
// ビューポート行列
Matrix3x3 MyCamera::viewPortMatrix;