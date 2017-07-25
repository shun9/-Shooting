//************************************************/
//* @file  :PlayerAttackState.h
//* @brief :�v���C���[�̍U�������
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_Timer.h>

class Player;

class PlayerAttackState : public ShunLib::State<Player>
{
private:
	ShunLib::Timer m_timer;

	//��������̑���s�\����
	const int m_shootInterval;

public:
	//�J�n����
	void Enter(Player* player)override;

	//���s����
	void Execute(Player* player)override;

	//�I������
	void Exit(Player* player)override;

public:
	PlayerAttackState() :m_shootInterval(10) {}
	~PlayerAttackState() {}
};