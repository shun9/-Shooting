//************************************************/
//* @file  :EnemyRotationState.cpp
//* @brief :“G‚Ì‰ñ“]ó‘Ô
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "EnemyRotationState.h"
#include "../Enemy.h"

void EnemyRotationState::Enter(Enemy * enemy)
{
	//ƒ^ƒO‚ð’e‚É‚·‚é
	//“G“¯Žm‚Å“–‚½‚é‚æ‚¤‚É‚È‚é
	enemy->Tag(Object::TAG_LIST::BULLET);
}

void EnemyRotationState::Execute(Enemy * enemy)
{
	//ˆÚ“®‚³‚¹‚é
	auto pos = enemy->Pos();

	pos -= enemy->Spd() / 60.0f;

	enemy->Pos(pos);

	//‰ñ“]‚³‚¹‚é
	enemy->Angle(enemy->Angle() + 20.0f);
}

void EnemyRotationState::Exit(Enemy * enemy)
{
}
