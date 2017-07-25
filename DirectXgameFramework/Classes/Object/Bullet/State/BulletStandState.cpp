//************************************************/
//* @file  :BulletStandState.cpp
//* @brief :�e�̑ҋ@���
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#include "BulletStandState.h"
#include "../Bullet.h"

void BulletStandState::Enter(Bullet * bullet)
{
	bullet->IsStandState(true);
	bullet->Angle(0.0f);

}

void BulletStandState::Execute(Bullet * bullet)
{
	auto playerPos = bullet->Player()->Pos();


	bullet->Pos(playerPos+ShunLib::Vec3(0.0f,0.0f,2.0f));

}

void BulletStandState::Exit(Bullet * bullet)
{
	bullet->IsStandState(false);

}