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
	MyCamera camera;
	// オブジェクトマネージャー
	ObjectManager objectManager;

	// キー入力状態初期化
	MyInput::Initialize();
	// カメラ初期化
	camera.Initialize({ 0.0f, 0.0f });
	// オブジェクト初期化
	objectManager.Initialize();


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
		camera.Update({ 0.0f, 0.0f });

		// オブジェクト更新処理
		objectManager.Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		// オブジェクト描画処理
		objectManager.Draw();

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
