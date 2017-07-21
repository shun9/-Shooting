//************************************************/
//* @file  :EnemyRotationState.cpp
//* @brief :�G�̉�]���
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "EnemyRotationState.h"
#include "../Enemy.h"

void EnemyRotationState::Enter(Enemy * enemy)
{
	//�^�O��e�ɂ���
	//�G���m�œ�����悤�ɂȂ�
	enemy->Tag(Object::TAG_LIST::BULLET);
}

void EnemyRotationState::Execute(Enemy * enemy)
{
	//�ړ�������
	auto pos = enemy->Pos();

	pos -= enemy->Spd() / 60.0f;

	enemy->Pos(pos);

	//��]������
	enemy->Angle(enemy->Angle() + 20.0f);
}

void EnemyRotationState::Exit(Enemy * enemy)
{
}
