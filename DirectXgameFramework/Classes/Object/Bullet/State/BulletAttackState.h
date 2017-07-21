//************************************************/
//* @file  :BulletAttackState.h
//* @brief :�e�̍U�������
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Bullet;

class BulletAttackState : public ShunLib::State<Bullet>
{
public:
	//�J�n����
	void Enter(Bullet* bullet)override;

	//���s����
	void Execute(Bullet* bullet)override;

	//�I������
	void Exit(Bullet* bullet)override;

public:
	BulletAttackState() {}
	~BulletAttackState() {}
};