//************************************************/
//* @file  :Bullet.cpp
//* @brief :プレイヤーの発射する弾クラス
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#include "Bullet.h"
#include "State\BulletAttackState.h"

using namespace ShunLib;

Bullet::Bullet():
	m_isAttackState(false),
	m_canShoot(true)
{
	m_tag = Object::TAG_LIST::BULLET;

	//初期位置
	m_pos = Vec3(0.0f, 0.0f, -10.0f);

	//速度
	m_spd = Vec3(0.0f, 0.0f, 3.0f);
	//状態管理用
	m_stateMachine = new StateMachine<Bullet>(this);
	m_stateMachine->ChangeState(new BulletAttackState);

}

Bullet::~Bullet()
{
}

void Bullet::Hit(TAG_LIST tag)
{
}

