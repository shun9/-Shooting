//************************************************/
//* @file  :PlayerMoveState.h
//* @brief :�v���C���[�̈ړ����
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_Singleton.h>
#include "../Player.h"

class PlayerMoveState : public ShunLib::State<Player>
{
public:
	//�J�n����
	void Enter(Player* player)override;

	//���s����
	void Execute(Player* player)override;

	//�I������
	void Exit(Player* player)override;

public:
	PlayerMoveState() {}
	~PlayerMoveState() {}
};