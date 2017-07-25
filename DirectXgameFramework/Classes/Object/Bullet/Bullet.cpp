//************************************************/
//* @file  :Bullet.cpp
//* @brief :プレイヤーの発射する弾クラス
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#include "Bullet.h"
#include "State\BulletAttackState.h"
#include "State\BulletReturnState.h"
#include "State\BulletStandState.h"

using namespace ShunLib;

Bullet::Bullet():
	m_isAttackState(false),
	m_isReturnState(false),
	m_isStandState(false)
{
	m_tag = Object::TAG_LIST::BULLET;

	//初期位置
	m_pos = Vec3(0.0f, 0.0f, 10.0f);

	//速度
	m_spd = Vec3(0.0f, 0.0f, 20.0f);

	//状態管理用
	m_stateMachine = new StateMachine<Bullet>(this);
	m_stateMachine->ChangeState(new BulletStandState);

}

Bullet::~Bullet()
{
	DELETE_POINTER(m_stateMachine);
}

void Bullet::Update()
{
	m_stateMachine->Update();
}

void Bullet::Hit(const Object& obj)
{
	//敵と当たったら戻ってくる
	if (obj.Tag() == Object::TAG_LIST::ENEMY)
	{
		if (IsAttackState())
		{
			m_stateMachine->ChangeState(new BulletReturnState);
		}
	}

	//戻ってきたら待機
	if (obj.Tag() == Object::TAG_LIST::PLAYER)
	{
		if (IsReturnState())
		{
			m_stateMachine->ChangeState(new BulletStandState);
		}
	}
}


/// <summary>
/// 範囲外に出た時の処理
/// </summary>
void Bullet::Clamp(float top, float bottom, float right, float left)
{
	//画面端まで行ったら戻ってくる
	if (bottom > m_pos.m_z)
	{
		m_stateMachine->ChangeState(new BulletReturnState);
	}
}

/// <summary>
/// 撃つ
/// </summary>
void Bullet::Shoot()
{
	//待機中なら撃てる
	if (IsStandState())
	{
		m_stateMachine->ChangeState(new BulletAttackState);
	}
}

