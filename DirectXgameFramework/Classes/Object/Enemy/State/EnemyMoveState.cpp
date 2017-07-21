//************************************************/
//* @file  :EnemyMoveState.cpp
//* @brief :“G‚ÌˆÚ“®ó‘Ô
//* @date  :2017/07/21
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

	pos += enemy->Spd() / 60.0f;

	enemy->Pos(pos);
}

void EnemyMoveState::Exit(Enemy * enemy)
{
}
