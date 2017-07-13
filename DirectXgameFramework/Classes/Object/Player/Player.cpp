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
