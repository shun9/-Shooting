//************************************************/
//* @file  :EnemyMoveState.h
//* @brief :�G�̈ړ����
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Enemy;

class EnemyMoveState : public ShunLib::State<Enemy>
{
public:
	//�J�n����
	void Enter(Enemy* enemy)override;

	//���s����
	void Execute(Enemy* enemy)override;

	//�I������
	void Exit(Enemy* enemy)override;

public:
	EnemyMoveState() {}
	~EnemyMoveState() {}
};