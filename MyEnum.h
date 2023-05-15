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
	// プレイヤー
	TypePlayer,
	// 敵
	TypeEnemy
};