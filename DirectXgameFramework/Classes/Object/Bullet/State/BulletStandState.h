//************************************************/
//* @file  :BulletStandState.h
//* @brief :�e�̑ҋ@�����
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Bullet;

class BulletStandState : public ShunLib::State<Bullet>
{
public:
	//�J�n����
	void Enter(Bullet* bullet)override;

	//���s����
	void Execute(Bullet* bullet)override;

	//�I������
	void Exit(Bullet* bullet)override;

public:
	BulletStandState() {}
	~BulletStandState() {}
};