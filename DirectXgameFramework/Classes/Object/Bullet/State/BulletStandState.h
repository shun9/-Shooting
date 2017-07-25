//************************************************/
//* @file  :BulletStandState.h
//* @brief :弾の待機中状態
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Bullet;

class BulletStandState : public ShunLib::State<Bullet>
{
public:
	//開始処理
	void Enter(Bullet* bullet)override;

	//実行処理
	void Execute(Bullet* bullet)override;

	//終了処理
	void Exit(Bullet* bullet)override;

public:
	BulletStandState() {}
	~BulletStandState() {}
};