#pragma once
#include <cmath>
#include <cassert>
#include "Vector2.h"
#include "Matrix3x3.h"
#include "MyStruct.h"

/// <summary>
/// 二次元座標系の計算クラス
/// </summary>
class MyMath
{
public:

#pragma region 線形補間関数

	/// <summary>
	/// 線形補間関数(Normal)(float)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static float LinearF(float t, float start, float end, float time);

	/// <summary>
	/// 線形補間関数(EaseIn)(float)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static float EaseInF(float t, float start, float end, float time);

	/// <summary>
	/// 線形補間関数(EaseOut)(float)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static float EaseOutF(float t, float start, float end, float time);

	/// <summary>
	/// 線形補間関数(Normal)(int)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static int LinearI(float t, int start, int end, float time);

	/// <summary>
	/// 線形補間関数(EaseIn)(int)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static int EaseInI(float t, int start, int end, float time);

	/// <summary>
	/// 線形補間関数(EaseOut)(int)
	/// </summary>
	/// <param name="t">現在のt</param>
	/// <param name="start">開始値</param>
	/// <param name="end">終了値</param>
	/// <param name="time">かかる秒数</param>
	/// <returns>イージングされた値(float)</returns>
	static int EaseOutI(float t, int start, int end, float time);

#pragma endregion

	/// <summary>
	/// 二次元ベクトルを指定された値でスカラー倍する関数
	/// </summary>
	/// <param name="k">何倍にするか</param>
	/// <param name="v1">計算するベクトル</param>
	/// <returns>計算結果</returns>
	static Vector2 Vector2Multiply(const float k, const Vector2& v1);

	/// <summary>
	/// ベクトルの内積を求める関数
	/// </summary>
	/// <param name="v1">ベクトル1</param>
	/// <param name="v2">ベクトル2</param>
	/// <returns>計算結果</returns>
	static float Dot(const Vector2& v1, const Vector2& v2);

	/// <summary>
	/// ベクトルの長さを求める関数
	/// </summary>
	/// <param name="v">ベクトル</param>
	/// <returns>ベクトル長さ</returns>
	static float Length(const Vector2& v);

	/// <summary>
	/// ベクトルの正規化を行う関数
	/// </summary>
	/// <param name="v">ベクトル</param>
	/// <returns>正規化ベクトル</returns>
	static Vector2 Normalize(const Vector2& v);

	/// <summary>
	/// 位置座標をスクリーン座標に変換する関数
	/// </summary>
	/// <param name="v">二次元ベクトル</param>
	/// <param name="m">行列</param>
	/// <returns>変換されたスクリーン座標</returns>
	static Vector2 Transform(Vector2 v, Matrix3x3 m);

	/// <summary>
	/// 行列の乗算
	/// </summary>
	/// <param name="m1">行列1</param>
	/// <param name="m2">行列2</param>
	/// <returns>計算結果</returns>
	static Matrix3x3 Multiply(const Matrix3x3& m1, const Matrix3x3& m2);

	/// <summary>
	/// 逆行列生成関数
	/// </summary>
	/// <param name="matrix">行列</param>
	/// <returns>逆行列</returns>
	static Matrix3x3 Inverse(const Matrix3x3& matrix);

	/// <summary>
	/// 平行移動行列生成関数
	/// </summary>
	/// <param name="v">位置</param>
	/// <returns>平行移動行列</returns>
	static Matrix3x3 MakeTranslateMatrix(const Vector2& translate);

	/// <summary>
	/// 拡大縮小行列生成関数
	/// </summary>
	/// <param name="scale">大きさ</param>
	/// <returns>拡大縮小行列</returns>
	static Matrix3x3 MakeScaleMatrix(const Vector2& scale);

	/// <summary>
	/// 回転行列生成関数
	/// </summary>
	/// <param name="radian">角度</param>
	/// <returns>回転行列</returns>
	static Matrix3x3 MakeRotateMatrix(const float& radian);

	/// <summary>
	/// アフィン行列生成関数
	/// </summary>
	/// <param name="scale">大きさ</param>
	/// <param name="theta">回転角</param>
	/// <param name="translate">位置座標</param>
	/// <returns>アフィン行列</returns>
	static Matrix3x3 MakeAffineMatrix(const Vector2& scale, const float& theta, const Vector2& translate);

	/// <summary>
	/// 正射影行列生成関数
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="right">右</param>
	/// <param name="bottom">下</param>
	/// <returns>正射影行列</returns>
	static Matrix3x3 MakeOrthGraphicMatrix(const float& left, const float& top,
		const float& right, const float& bottom);

	/// <summary>
	/// ビューポート行列生成関数
	/// </summary>
	/// <param name="left">左</param>
	/// <param name="top">上</param>
	/// <param name="width">幅</param>
	/// <param name="height">高さ</param>
	/// <returns>ビューポート行列</returns>
	static Matrix3x3 MakeViewportMatrix(const float& left, const float& top,
		const float& width, const float& height);

	/// <summary>
	/// 矩形同士の当たり判定を調べる関数
	/// </summary>
	/// <param name="lT1">矩形1の左上頂点</param>
	/// <param name="rB1">矩形1の右下頂点</param>
	/// <param name="lt2">矩形2の左上頂点</param>
	/// <param name="rB2">矩形2の右下頂点</param>
	/// <returns>矩形同士が当たっているか</returns>
	static bool CheckHitQuad(Vector2 lT1, Vector2 rB1, Vector2 lT2, Vector2 rB2);

};