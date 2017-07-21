//************************************************/
//* @file  :EnemyRotationState.h
//* @brief :�G�̉�]���
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Enemy;

class EnemyRotationState : public ShunLib::State<Enemy>
{
public:
	//�J�n����
	void Enter(Enemy* enemy)override;

	//���s����
	void Execute(Enemy* enemy)override;

	//�I������
	void Exit(Enemy* enemy)override;

public:
	EnemyRotationState() {}
	~EnemyRotationState() {}
};