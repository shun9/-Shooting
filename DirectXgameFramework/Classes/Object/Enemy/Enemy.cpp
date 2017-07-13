//************************************************/
//* @file  :Enemy.cpp
//* @brief :�G�N���X
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "Enemy.h"
#include <SL_MacroConstants.h>
#include "State\EnemyMoveState.h"

using namespace ShunLib;

Enemy::Enemy()
{
	//�����ʒu
	m_pos = Vec3(0.0f, 0.0f, -10.0f);

	//���x
	m_spd = Vec3(0.0f,0.0f,3.0f);

	//��ԊǗ��p
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
