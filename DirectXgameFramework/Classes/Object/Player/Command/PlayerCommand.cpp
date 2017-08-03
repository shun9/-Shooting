//************************************************/
//* @file  :PlayerCommand.cpp
//* @brief :プレイヤーのコマンドまとめ
//* @date  :2017/08/03
//* @author:S.Katou
//************************************************/
#include "PlayerCommand.h"
#include "../Player.h"
#include "../State/PlayerAttackState.h"

void PlayerRightMoveCommand::Execute(Player * player)
{
	auto pos = player->Pos();
	pos.m_x += player->Spd().m_x/60.0f;
	player->Pos(pos);
}

void PlayerLeftMoveCommand::Execute(Player * player)
{
	auto pos = player->Pos();
	pos.m_x -= player->Spd().m_x/60.0f;
	player->Pos(pos);
}

void PlayerShootCommand::Execute(Player * player)
{
	player->ChangeState(new PlayerAttackState);
}
