//************************************************/
//* @file  :EnemyRotationState.h
//* @brief :敵の回転状態
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Enemy;

class EnemyRotationState : public ShunLib::State<Enemy>
{
public:
	//開始処理
	void Enter(Enemy* enemy)override;

	//実行処理
	void Execute(Enemy* enemy)override;

	//終了処理
	void Exit(Enemy* enemy)override;

public:
	EnemyRotationState() {}
	~EnemyRotationState() {}
};