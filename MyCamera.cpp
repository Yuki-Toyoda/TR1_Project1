#include "MyCamera.h"
#include "MyConst.h"

/// <summary>
/// 初期化処理
/// </summary>
/// <param name="translate_">カメラ中心座標</param>
void MyCamera::Initialize(Vector2 translate_) {

	// 引数の値をメンバ変数に代入
	this->translate = translate_;
	// カメラの拡大率初期化
	this->scale = { 1.0f, 1.0f };

	// カメラの設定
	SetUpCamera({ -(float)kWindowWidth / 2, (float)kWindowHeight / 2 }, 
		{ (float)kWindowWidth / 2, -(float)kWindowHeight / 2 }, 
		{ 0.0f, 0.0f }, 
		{ (float)kWindowWidth, (float)kWindowHeight });

	// 変換
	cameraMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);
	viewMatrix = MyMath::Inverse(cameraMatrix);
	orthoMatrix = MyMath::MakeOrthGraphicMatrix(orthoLeftTop.x, orthoLeftTop.y, orthoRightBottom.x, orthoRightBottom.y);
	viewPortMatrix = MyMath::MakeViewportMatrix(viewPortLeftTop.x, viewPortLeftTop.y, viewPortRightBottom.x, viewPortRightBottom.y);
	vpvpMatrix = MyMath::Multiply(MyMath::Multiply(viewMatrix, orthoMatrix),  viewPortMatrix);
}

/// <summary>
/// 更新処理
/// </summary>
/// <param name="translate_">カメラ中心座標</param>
void MyCamera::Update(Vector2 translate_) {

	// 引数の値をメンバ変数に代入
	this->translate = translate_;

	// 変換
	cameraMatrix = MyMath::MakeAffineMatrix(scale, 0.0f, translate);
	viewMatrix = MyMath::Inverse(cameraMatrix);
	orthoMatrix = MyMath::MakeOrthGraphicMatrix(orthoLeftTop.x, orthoLeftTop.y, orthoRightBottom.x, orthoRightBottom.y);
	viewPortMatrix = MyMath::MakeViewportMatrix(viewPortLeftTop.x, viewPortLeftTop.y, viewPortRightBottom.x, viewPortRightBottom.y);
	vpvpMatrix = MyMath::Multiply(MyMath::Multiply(viewMatrix, orthoMatrix), viewPortMatrix);

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
	this->orthoLeftTop = clipLeftTop_;
	this->orthoRightBottom = clipRightBottom_;
	this->viewPortLeftTop  = viewPortLeftTop_;
	this->viewPortRightBottom = viewPortRightBottom_;

}
