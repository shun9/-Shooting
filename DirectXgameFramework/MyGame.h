#pragma once

#ifndef MYGAME
#define MYGAME

#include "Game.h"

class MyGame : public Game {
public:
	// コンストラクタ Constructor
	MyGame(int width, int height);
	// ゲームオブジェクトを初期する Initialize game object
	void Initialize() override;
	// ゲームを更新する Update game
	void Update(DX::StepTimer const& timer) override;
	// ゲームシーンを描画する Draws the scene
	void Render(DX::StepTimer const& timer) override;
	// 終了処理をおこなう Finalize game
	void Finalize() override;
};

#endif	// MYGAME
