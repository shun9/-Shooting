//************************************************/
//* @file  :Enemy.cpp
//* @brief :敵クラス
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "Enemy.h"
#include <SL_MacroConstants.h>
#include "State\EnemyMoveState.h"

using namespace ShunLib;

Enemy::Enemy()
{
	//初期位置
	m_pos = Vec3(0.0f, 0.0f, -10.0f);

	//速度
	m_spd = Vec3(0.0f,0.0f,3.0f);

	//状態管理用
	m_stateMachine = new StateMachine<Enemy>(this);
	m_stateMachine->ChangeState(new EnemyMoveState);
}

Enemy::~Enemy()
{
	DELETE_POINTER(m_stateMachine);

}

void Enemy::Update()
{
	m_stateMachine->Update();
}
