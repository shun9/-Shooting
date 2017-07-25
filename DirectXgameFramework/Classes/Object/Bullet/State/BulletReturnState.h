//************************************************/
//* @file  :BulletReturnState.h
//* @brief :弾の戻ってくる状態
//* @date  :2017/07/22
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Bullet;

class BulletReturnState : public ShunLib::State<Bullet>
{
public:
	//開始処理
	void Enter(Bullet* bullet)override;

	//実行処理
	void Execute(Bullet* bullet)override;

	//終了処理
	void Exit(Bullet* bullet)override;

public:
	BulletReturnState() {}
	~BulletReturnState() {}
};