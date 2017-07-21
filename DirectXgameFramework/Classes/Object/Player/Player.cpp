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
	m_tag = Object::TAG_LIST::PLAYER;

	//�����ʒu
	this->Pos(Vec3(1.0f, 0.0f, 10.0f));

	//���x
	this->Spd(Vec3(10.0f, 0.0f, 0.0f));

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

void Player::Hit(TAG_LIST tag)
{
}

void Player::Clamp(float top, float bottom, float right, float left)
{
	if (right < m_pos.m_x)
	{
		m_pos.m_x = right;
	}

	if (left > m_pos.m_x)
	{
		m_pos.m_x = left;
	}
}
