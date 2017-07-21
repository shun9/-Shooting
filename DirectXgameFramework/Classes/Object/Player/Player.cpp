//************************************************/
//* @file  :Player.cpp
//* @brief :プレイヤークラス
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

	//初期位置
	this->Pos(Vec3(1.0f, 0.0f, 10.0f));

	//速度
	this->Spd(Vec3(10.0f, 0.0f, 0.0f));

	//状態管理用
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
