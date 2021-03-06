//************************************************/
//* @file  :EnemyRotationState.cpp
//* @brief :敵の回転状態
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "EnemyRotationState.h"
#include "../Enemy.h"

void EnemyRotationState::Enter(Enemy * enemy)
{
	//タグを弾にする
	//敵同士で当たるようになる
	enemy->Tag(Object::TAG_LIST::BULLET);
}

void EnemyRotationState::Execute(Enemy * enemy)
{
	//移動させる
	auto pos = enemy->Pos();

	pos -= enemy->Spd() / 60.0f;

	enemy->Pos(pos);

	//回転させる
	enemy->Angle(enemy->Angle() + 20.0f);
}

void EnemyRotationState::Exit(Enemy * enemy)
{
}
