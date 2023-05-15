#pragma once
#include "Object.h"
class ObjectManager
{
public:

	/// <summary>
	/// 全てのオブジェクトをObjectで初期化する処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 全てのオブジェクトを更新する処理
	/// </summary>
	void Update();

	/// <summary>
	/// 全てのオブジェクトを描画する関数
	/// </summary>
	void Draw();

#pragma region オブジェクトのインスタンスを作成する関数群



#pragma endregion

#pragma region アクセッサ

	/// <summary>
	/// 指定したオブジェクトを取得する関数
	/// </summary>
	/// <param name="objectType">取得するオブジェクトのタイプ</param>
	/// <returns></returns>
	Object* GetSelectObject(ObjectType objectType);

#pragma endregion

private:

	// 生成できるオブジェクトの数
	const static int kMaxObjectSize = 64;

	// オブジェクトのポインタ達
	Object* object[kMaxObjectSize];

	// ゲーム時間
	float timeScale;

};

