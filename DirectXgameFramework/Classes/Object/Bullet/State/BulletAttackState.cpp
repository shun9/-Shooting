//************************************************/
//* @file  :BulletAttackState.cpp
//* @brief :�e�̍U�������
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "BulletAttackState.h"
#include "../Bullet.h"

void BulletAttackState::Enter(Bullet* bullet)
{
	//�U����
	bullet->IsAttackState(true);

	//���ĂȂ�
	bullet->CanShoot(false);
}

void BulletAttackState::Execute(Bullet* bullet)
{
	auto pos = bullet->Pos();

	pos.m_z += bullet->Spd().m_z / 60.0f;

	bullet->Pos(pos);

}

void BulletAttackState::Exit(Bullet* bullet)
{
	bullet->IsAttackState(false);
}
