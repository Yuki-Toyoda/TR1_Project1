#pragma once
#include "Object.h"
#include "Player.h"
#include "Enemy.h"
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

	/// <summary>
	/// プレイヤーのインスタンスを生成する関数
	/// </summary>
	/// <param name="translate_">プレイヤーの初期座標</param>
	void MakeNewObjectPlayer(Vector2 translate_);

	/// <summary>
	/// 敵のインスタンスを生成する関数
	/// </summary>
	/// <param name="translate_">敵の初期座標</param>
	void MakeNewObjectEnemy(Vector2 translate_);

#pragma endregion

#pragma region アクセッサ

	/// <summary>
	/// 指定したオブジェクトを取得する関数
	/// </summary>
	/// <param name="objectType">取得するオブジェクトのタイプ</param>
	/// <returns></returns>
	Object* GetSelectObject(ObjectType objectType);

#pragma endregion

#pragma region TimeScaleを動かす関数

	/// <summary>
	/// TimeScaleを引数で指定した値にセットする関数
	/// </summary>
	/// <param name="timeScale_">設定する時間</param>
	void SetTime(float timeScale_);

#pragma endregion

#pragma region 当たり判定

	/// <summary>
	/// 指定したオブジェクト同士が当たっているかを調べる関数
	/// </summary>
	/// <param name="object1">調べるオブジェクト1</param>
	/// <param name="object2">調べるオブジェクト2</param>
	bool CheckHitObject(Object* object1, Object* object2);

	/// <summary>
	/// オブジェクト間の当たり判定全てを検知する関数
	/// </summary>
	void CheckAllCollisions();

#pragma endregion


private:

	// 生成できるオブジェクトの数
	const static int kMaxObjectSize = 64;

	// オブジェクトのポインタ達
	Object* object[kMaxObjectSize];

	// ゲーム時間
	float timeScale;

	// イージングの際に用いるゲーム時間
	float prevTimeScale;
	// TimeScaleのイージング用t
	float t;
	// 時間を遷移させている時にTrue
	bool transitioningTime;

};

