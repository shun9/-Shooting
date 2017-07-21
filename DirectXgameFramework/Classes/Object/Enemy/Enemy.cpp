//************************************************/
//* @file  :Enemy.cpp
//* @brief :敵クラス
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

	//状態管理用
	m_stateMachine = new StateMachine<Enemy>(this);
	m_stateMachine->ChangeState(new EnemyMoveState);
}

Enemy::Enemy(const Enemy& enemy) :
	m_score(1)
{
	m_tag = Object::TAG_LIST::ENEMY;

	//初期位置
	m_pos = enemy.m_pos;

	//速度
	m_spd = enemy.m_spd;

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

/// <summary>
/// 当たったときの処理
/// </summary>
/// <param name="tag">相手のタグ</param>
void Enemy::Hit(TAG_LIST tag)
{
	if (tag!=Object::TAG_LIST::ENEMY)
	{
		ChangeState(new EnemyRotationState);
	}
}

/// <summary>
/// 範囲外に出た時の処理
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

