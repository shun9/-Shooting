//************************************************/
//* @file  :Player.cpp
//* @brief :�v���C���[�N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#include "Player.h"

#include <SL_MacroConstants.h>
#include "State\PlayerMoveState.h"

using namespace ShunLib;

Player::Player()
{
	//�����ʒu
	this->Pos(Vec3(1.0f, 0.0f, 10.0f));

	//���x
	this->Spd(Vec3(5.0f, 0.0f, 0.0f));

	//��ԊǗ��p
	m_stateMachine = new StateMachine<Player>(this);
	m_stateMachine->ChangeState(new PlayerMoveState);
}

Player::~Player()
{
	DELETE_POINTER(m_stateMachine);
}

void Player::Update()
{
	m_stateMachine->Update();
}
