#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <time.h>

/// 定数管理クラス

// ウィンドウの名前
const char kWindowTitle[] = "LE2A_11_トヨダユウキ";
/// ウィンドウサイズ
// 縦
static const int kWindowWidth = 1280;
// 横
static const int kWindowHeight = 720;

// TimeScale限界値
// 最大値
static const int kMaxTimeScale = 8.0f;
// 最小値
static const int kMinTimeScale = 0.1f;

// マップチップサイズ
static const int kMapChipSizeWidht = 32;
static const int kMapChipSizeHeight = 32;

// 床高さ
static const float kFloorHeight = 20.0f;

// 加速度限界値
static const float kVelocityLimit = 10.0f;
