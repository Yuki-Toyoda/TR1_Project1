#pragma once

/// 列挙子管理クラス

// マウス入力検知
enum MouseButton
{
	LeftClick,
	RightClick
};

// 入力状態検知
enum InputState
{
	Null,
	Trigger,
	Press
};

// オブジェクトのタイプ
enum ObjectType
{
	// オブジェクト
	TypeObject,
	// プレイヤー自体
	TypePlayer,
	// プレイヤーの武器
	TypePlayerWeapon,
	// 敵
	TypeEnemy
};

enum EasingType {
	// ノーマル
	TypeEaseNormal,
	// イーズイン
	TypeEaseIn,
	// イーズアウト
	TypeEaseOut
};

enum MapChipType {

	// 空白マス
	TypeAir,
	// 通常のマス
	TypeNormal

};