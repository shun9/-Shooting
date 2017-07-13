//************************************************/
//* @file  :PlayerMoveState.cpp
//* @brief :ƒvƒŒƒCƒ„[‚ÌˆÚ“®ó‘Ô
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "PlayerMoveState.h"
#include <SL_KeyManager.h>
#include "../Player.h"

void PlayerMoveState::Enter(Player * player)
{

}

void PlayerMoveState::Execute(Player* player)
{
	using namespace ShunLib;
	auto key = KeyManager::GetInstance();
	auto pos = player->Pos();
	if (key->IsPushed(KeyManager::KEY_CODE::RIGHT))
	{
		pos.m_x += (player->Spd().m_x /60.0f);
	}

	if (key->IsPushed(KeyManager::KEY_CODE::LEFT))
	{
		pos.m_x -= player->Spd().m_x / 60.0f;
	}
	player->Pos(pos);
}

void PlayerMoveState::Exit(Player* player)
{
}
