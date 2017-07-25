//************************************************/
//* @file  :BulletReturnState.h
//* @brief :�e�̖߂��Ă�����
//* @date  :2017/07/22
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>

class Bullet;

class BulletReturnState : public ShunLib::State<Bullet>
{
public:
	//�J�n����
	void Enter(Bullet* bullet)override;

	//���s����
	void Execute(Bullet* bullet)override;

	//�I������
	void Exit(Bullet* bullet)override;

public:
	BulletReturnState() {}
	~BulletReturnState() {}
};