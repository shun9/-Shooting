//************************************************/
//* @file  :BulletReturnState.cpp
//* @brief :弾の戻ってくる状態
//* @date  :2017/07/22
//* @author:S.Katou
//************************************************/
#include "BulletReturnState.h"
#include "../Bullet.h"

void BulletReturnState::Enter(Bullet * bullet)
{
	bullet->IsReturnState(true);
	bullet->Angle(0.0f);

}

void BulletReturnState::Execute(Bullet * bullet)
{
	auto bulletPos = bullet->Pos();
	auto playerPos = bullet->Player()->Pos();

	//プレイヤーへの方向ベクトル
	auto direction = playerPos - bulletPos;
	direction.Normalize();

	bulletPos += (direction * bullet->Spd().m_z) / 60.0f;

	bullet->Pos(bulletPos);
}

void BulletReturnState::Exit(Bullet * bullet)
{
	bullet->IsReturnState(false);
}
