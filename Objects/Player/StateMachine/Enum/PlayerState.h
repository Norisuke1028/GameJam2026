#pragma once

enum class ePlayerState : unsigned char
{
	IDLE = 0,  // 何もしてない
	ROLL,    // 転がる（ローリング）
	JUMP,    // ジャンプ
	GOOL,    // ゴール
	DIE,     // 死
	NONE,    // 状態なし
};