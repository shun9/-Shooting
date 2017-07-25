//************************************************/
//* @file  :Bullet.cpp
//* @brief :�v���C���[�̔��˂���e�N���X
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

	//�����ʒu
	m_pos = Vec3(0.0f, 0.0f, 10.0f);

	//���x
	m_spd = Vec3(0.0f, 0.0f, 20.0f);

	//��ԊǗ��p
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
	//�G�Ɠ���������߂��Ă���
	if (obj.Tag() == Object::TAG_LIST::ENEMY)
	{
		if (IsAttackState())
		{
			m_stateMachine->ChangeState(new BulletReturnState);
		}
	}

	//�߂��Ă�����ҋ@
	if (obj.Tag() == Object::TAG_LIST::PLAYER)
	{
		if (IsReturnState())
		{
			m_stateMachine->ChangeState(new BulletStandState);
		}
	}
}


/// <summary>
/// �͈͊O�ɏo�����̏���
/// </summary>
void Bullet::Clamp(float top, float bottom, float right, float left)
{
	//��ʒ[�܂ōs������߂��Ă���
	if (bottom > m_pos.m_z)
	{
		m_stateMachine->ChangeState(new BulletReturnState);
	}
}

/// <summary>
/// ����
/// </summary>
void Bullet::Shoot()
{
	//�ҋ@���Ȃ猂�Ă�
	if (IsStandState())
	{
		m_stateMachine->ChangeState(new BulletAttackState);
	}
}

