#include <Novice.h>
#include "MyConst.h"
#include "MyInput.h"
#include "MyCamera.h"
#include "ObjectManager.h"

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kWindowWidth, kWindowHeight);

	// カメラ
	//MyCamera camera;
	// オブジェクトマネージャー
	ObjectManager objectManager;

	// キー入力状態初期化
	MyInput::Initialize();
	// カメラ初期化
	Vector2 translate = { (float)kWindowWidth / 2, (float)kWindowHeight / 2 };
	MyCamera::Initialize(translate);
	// オブジェクト初期化
	objectManager.Initialize();

	objectManager.MakeNewObjectPlayer({ 640.0f, 360.0f });

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		///
		/// ↓更新処理ここから
		///

		// キー入力検知
		MyInput::Update();
		// カメラ更新
		MyCamera::Update(translate);

		// オブジェクト更新処理
		objectManager.Update();

		if (MyInput::GetKeybordState(DIK_RIGHT, Press)) {
			translate.x += 1.0f;
		}
		else if (MyInput::GetKeybordState(DIK_LEFT, Press)) {
			translate.x -= 1.0f;
		}

		if (MyInput::GetKeybordState(DIK_UP, Press)) {
			translate.y += 1.0f;
		}
		else if (MyInput::GetKeybordState(DIK_DOWN, Press)) {
			translate.y -= 1.0f;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// オブジェクト描画処理
		objectManager.Draw();

		// デバック描画
		Novice::ScreenPrintf(0, 40, "camera : x = %4.2f y = %4.2f", translate.x, translate.y);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (MyInput::GetKeybordState(DIK_ESCAPE, Trigger)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
