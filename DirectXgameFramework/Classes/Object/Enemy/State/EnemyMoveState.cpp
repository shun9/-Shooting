//************************************************/
//* @file  :EnemyMoveState.cpp
//* @brief :“G‚ÌˆÚ“®ó‘Ô
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "EnemyMoveState.h"
#include "../Enemy.h"

void EnemyMoveState::Enter(Enemy * enemy)
{
}

void EnemyMoveState::Execute(Enemy * enemy)
{
	auto pos = enemy->Pos();

	pos.m_z += enemy->Spd().m_z / 60.0f;

	enemy->Pos(pos);
}

void EnemyMoveState::Exit(Enemy * enemy)
{
}
