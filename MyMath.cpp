#include "MyMath.h"

Vector2 MyMath::Vector2Multiply(const float k, const Vector2& v1) {

	// 結果格納用
	Vector2 result;

	// 計算処理
	result.x = v1.x * k;
	result.y = v1.y * k;

	// 計算結果を返す
	return result;

}

/// <summary>
/// ベクトルの内積を求める関数
/// </summary>
/// <param name="v1">ベクトル1</param>
/// <param name="v2">ベクトル2</param>
/// <returns>計算結果</returns>
float MyMath::Dot(const Vector2& v1, const Vector2& v2) {

	// 計算結果格納用
	float result;

	// 計算処理
	result = (v1.x * v2.x) + (v1.y * v2.y);

	// 計算結果を返す
	return result;

}

/// <summary>
/// ベクトルの長さを求める関数
/// </summary>
/// <param name="v">ベクトル</param>
/// <returns>ベクトル長さ</returns>
float MyMath::Length(const Vector2& v) {

	// 計算処理をして値を返す
	return sqrtf(MyMath::Dot(v, v));


}

/// <summary>
/// ベクトルの正規化を行う関数
/// </summary>
/// <param name="v">ベクトル</param>
/// <returns>正規化ベクトル</returns>
Vector2 MyMath::Normalize(const Vector2& v) {

	// ベクトルの長さを求める
	float length = sqrtf(Length(v));
	// 計算結果格納用
	Vector2 result;

	// 計算処理
	if (v.x != 0.0f) {
		result.x = v.x / length;
	}
	else {
		result.x = 0.0f;
	}

	if (v.y != 0.0f) {
		result.y = v.y / length;
	}
	else {
		result.y = 0.0f;
	}

	// 計算結果を返す
	return result;

}

/// <summary>
/// 位置座標をスクリーン座標に変換する関数
/// </summary>
/// <param name="v">二次元ベクトル</param>
/// <param name="m">行列</param>
/// <returns>変換されたスクリーン座標</returns>
Vector2 MyMath::Transform(Vector2 v, Matrix3x3 m) {

	// 計算結果格納用
	Vector2 result;

	// 計算処理
	result.x = v.x * m.m[0][0] + v.y * m.m[1][0] + 1.0f * m.m[2][0];
	result.y = v.x * m.m[0][1] + v.y * m.m[1][1] + 1.0f * m.m[2][1];
	float w =  v.x * m.m[0][2] + v.y * m.m[1][2] + 1.0f * m.m[2][2];
	assert(w != 0.0f);
	result.x /= w;
	result.y /= w;

	// 結果を返す
	return result;
}

/// <summary>
/// 行列の乗算
/// </summary>
/// <param name="m1">行列1</param>
/// <param name="m2">行列2</param>
/// <returns>計算結果</returns>
Matrix3x3 MyMath::Multiply(const Matrix3x3& m1, const Matrix3x3& m2) {
	
	// 計算結果格納用
	Matrix3x3 result;

	// 計算処理
	result.m[0][0] = m1.m[0][0] * m2.m[0][0] + m1.m[0][1] * m2.m[1][0] + m1.m[0][2] * m2.m[2][0];
	result.m[0][1] = m1.m[0][0] * m2.m[0][1] + m1.m[0][1] * m2.m[1][1] + m1.m[0][2] * m2.m[2][1];
	result.m[0][2] = m1.m[0][0] * m2.m[0][2] + m1.m[0][1] * m2.m[1][2] + m1.m[0][2] * m2.m[2][2];

	result.m[1][0] = m1.m[1][0] * m2.m[0][0] + m1.m[1][1] * m2.m[1][0] + m1.m[1][2] * m2.m[2][0];
	result.m[1][1] = m1.m[1][0] * m2.m[0][1] + m1.m[1][1] * m2.m[1][1] + m1.m[1][2] * m2.m[2][1];
	result.m[1][2] = m1.m[1][0] * m2.m[0][2] + m1.m[1][1] * m2.m[1][2] + m1.m[1][2] * m2.m[2][2];

	result.m[2][0] = m1.m[2][0] * m2.m[0][0] + m1.m[2][1] * m2.m[1][0] + m1.m[2][2] * m2.m[2][0];
	result.m[2][1] = m1.m[2][0] * m2.m[0][1] + m1.m[2][1] * m2.m[1][1] + m1.m[2][2] * m2.m[2][1];
	result.m[2][2] = m1.m[2][0] * m2.m[0][2] + m1.m[2][1] * m2.m[1][2] + m1.m[2][2] * m2.m[2][2];

	// 結果を返す
	return result;
}

/// <summary>
/// 逆行列生成関数
/// </summary>
/// <param name="matrix">行列</param>
/// <returns>逆行列</returns>
Matrix3x3 MyMath::Inverse(const Matrix3x3& matrix) {

	Matrix3x3 result;
	float determinant = matrix.m[0][0] * matrix.m[1][1] * matrix.m[2][2] +
		matrix.m[0][1] * matrix.m[1][2] * matrix.m[2][0] +
		matrix.m[0][2] * matrix.m[1][0] * matrix.m[2][1] -
		matrix.m[0][2] * matrix.m[1][1] * matrix.m[2][0] -
		matrix.m[0][1] * matrix.m[1][0] * matrix.m[2][2] -
		matrix.m[0][0] * matrix.m[1][2] * matrix.m[2][1];
	assert(determinant != 0.0f);
	float determinantRecp = 1.0f / determinant;

	result.m[0][0] =
		(matrix.m[1][1] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][1]) * determinantRecp;
	result.m[0][1] =
		-(matrix.m[0][1] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][1]) * determinantRecp;
	result.m[0][2] =
		(matrix.m[0][1] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][1]) * determinantRecp;

	result.m[1][0] =
		-(matrix.m[1][0] * matrix.m[2][2] - matrix.m[1][2] * matrix.m[2][0]) * determinantRecp;
	result.m[1][1] =
		(matrix.m[0][0] * matrix.m[2][2] - matrix.m[0][2] * matrix.m[2][0]) * determinantRecp;
	result.m[1][2] =
		-(matrix.m[0][0] * matrix.m[1][2] - matrix.m[0][2] * matrix.m[1][0]) * determinantRecp;

	result.m[2][0] =
		(matrix.m[1][0] * matrix.m[2][1] - matrix.m[1][1] * matrix.m[2][0]) * determinantRecp;
	result.m[2][1] =
		-(matrix.m[0][0] * matrix.m[2][1] - matrix.m[0][1] * matrix.m[2][0]) * determinantRecp;
	result.m[2][2] =
		(matrix.m[0][0] * matrix.m[1][1] - matrix.m[0][1] * matrix.m[1][0]) * determinantRecp;
	return result;

}

/// <summary>
/// 平行移動行列生成関数
/// </summary>
/// <param name="v">位置</param>
/// <returns>平行移動行列</returns>
Matrix3x3 MyMath::MakeTranslateMatrix(const Vector2& translate) {

	// 結果格納用
	Matrix3x3 result;

	// 生成処理
	result.m[0][0] = 1.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 1.0f;
	result.m[1][2] = 0.0f;

	result.m[2][0] = translate.x;
	result.m[2][1] = translate.y;
	result.m[2][2] = 1.0f;

	// 生成結果を返す
	return result;

}

/// <summary>
/// 拡大縮小行列生成関数
/// </summary>
/// <param name="scale">大きさ</param>
/// <returns>拡大縮小行列</returns>
Matrix3x3 MyMath::MakeScaleMatrix(const Vector2& scale) {

	// 結果格納用
	Matrix3x3 result;

	// 生成処理
	result.m[0][0] = scale.x;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = scale.y;
	result.m[1][2] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;

	// 生成結果を返す
	return result;

}

/// <summary>
/// 回転行列生成関数
/// </summary>
/// <param name="radian">角度</param>
/// <returns>回転行列</returns>
Matrix3x3 MyMath::MakeRotateMatrix(const float& theta) {
	
	// 結果格納用
	Matrix3x3 result;

	// 生成処理
	result.m[0][0] = cosf(theta);
	result.m[0][1] = sinf(theta);
	result.m[0][2] = 0.0f;

	result.m[1][0] = -sin(theta);
	result.m[1][1] = cosf(theta);
	result.m[1][2] = 0.0f;

	result.m[2][0] = 0.0f;
	result.m[2][1] = 0.0f;
	result.m[2][2] = 1.0f;

	// 生成結果を返す
	
	return result;
}

/// <summary>
/// アフィン行列生成関数
/// </summary>
/// <param name="scale">大きさ</param>
/// <param name="theta">回転角</param>
/// <param name="translate">位置座標</param>
/// <returns>アフィン行列</returns>
Matrix3x3 MyMath::MakeAffineMatrix(const Vector2& scale, const float& theta, const Vector2& translate) {
	
	Matrix3x3 S = MakeScaleMatrix(scale);
	Matrix3x3 R = MakeRotateMatrix(theta);
	Matrix3x3 T = MakeTranslateMatrix(translate);

	Matrix3x3 result;

	// 計算処理
	result = Multiply(Multiply(S, R), T);

	// 生成結果を返す
	return result;

}

/// <summary>
/// 正射影行列生成関数
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="right">右</param>
/// <param name="bottom">下</param>
/// <returns>正射影行列</returns>
Matrix3x3 MyMath::MakeOrthGraphicMatrix(const float& left, const float& top,
	const float& right, const float& bottom) {
	assert(left != right);
	assert(top != bottom);
	// 計算結果格納用
	Matrix3x3 result;

	// 計算処理
	result.m[0][0] = 2.0f / (right - left);
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = 2.0f / (top - bottom);
	result.m[1][2] = 0.0f;

	result.m[2][0] = (left + right) / (left - right);
	result.m[2][1] = (top + bottom) / (bottom - top);
	result.m[2][2] = 1.0f;

	// 生成結果を返す
	return result;

}

/// <summary>
/// ビューポート行列生成関数
/// </summary>
/// <param name="left">左</param>
/// <param name="top">上</param>
/// <param name="width">幅</param>
/// <param name="height">高さ</param>
/// <returns>ビューポート行列</returns>
Matrix3x3 MyMath::MakeViewportMatrix(const float& left, const float& top,
	const float& width, const float& height) {

	// 計算結果格納用
	Matrix3x3 result;

	// 計算処理
	result.m[0][0] = width / 2.0f;
	result.m[0][1] = 0.0f;
	result.m[0][2] = 0.0f;

	result.m[1][0] = 0.0f;
	result.m[1][1] = -(height / 2.0f);
	result.m[1][2] = 0.0f;

	result.m[2][0] = left + (width / 2.0f);
	result.m[2][1] = top + (height / 2.0f);
	result.m[2][2] = 1.0f;

	// 計算結果を返す
	return result;

}