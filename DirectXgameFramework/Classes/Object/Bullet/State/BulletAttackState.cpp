//************************************************/
//* @file  :BulletAttackState.cpp
//* @brief :’e‚ÌUŒ‚’†ó‘Ô
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "BulletAttackState.h"
#include "../Bullet.h"

void BulletAttackState::Enter(Bullet* bullet)
{
	//UŒ‚’†
	bullet->IsAttackState(true);

	bullet->Angle(180.0f);
}

void BulletAttackState::Execute(Bullet* bullet)
{
	auto pos = bullet->Pos();

	pos.m_z -= bullet->Spd().m_z / 60.0f;

	bullet->Pos(pos);

}

void BulletAttackState::Exit(Bullet* bullet)
{
	bullet->IsAttackState(false);
}
