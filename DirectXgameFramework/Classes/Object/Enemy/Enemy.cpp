//************************************************/
//* @file  :Enemy.cpp
//* @brief :�G�N���X
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#include "Enemy.h"
#include <SL_MacroConstants.h>
#include "State\EnemyMoveState.h"
#include "State\EnemyRotationState.h"

const wchar_t* Enemy::enemyModel = L"CModel\\Enemy.cmo";

using namespace ShunLib;

Enemy::Enemy()
	:m_score(1)
{
	m_tag = Object::TAG_LIST::ENEMY;

	//��ԊǗ��p
	m_stateMachine = new StateMachine<Enemy>(this);
	m_stateMachine->ChangeState(new EnemyMoveState);
}

Enemy::Enemy(const Enemy& enemy) :
	m_score(1)
{
	m_tag = Object::TAG_LIST::ENEMY;

	//�����ʒu
	m_pos = enemy.m_pos;

	//���x
	m_spd = enemy.m_spd;

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

/// <summary>
/// ���������Ƃ��̏���
/// </summary>
/// <param name="tag">����̃^�O</param>
void Enemy::Hit(TAG_LIST tag)
{
	if (tag!=Object::TAG_LIST::ENEMY)
	{
		ChangeState(new EnemyRotationState);
	}
}

/// <summary>
/// �͈͊O�ɏo�����̏���
/// </summary>
void Enemy::Clamp(float top, float bottom, float right, float left)
{
	if (top < m_pos.m_z)
	{
		m_isDead = true;
	}

	if (bottom > m_pos.m_z)
	{
		m_isDead = true;
	}

	if (right < m_pos.m_x)
	{
		m_spd.m_x *= -1;
	}

	if (left > m_pos.m_x)
	{
		m_spd.m_x *= -1;
	}

}

