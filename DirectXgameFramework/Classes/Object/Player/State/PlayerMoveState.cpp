//************************************************/
//* @file  :PlayerMoveState.cpp
//* @brief :ƒvƒŒƒCƒ„[‚ÌˆÚ“®ó‘Ô
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "PlayerMoveState.h"
#include <SL_KeyManager.h>

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
		pos.m_x += 0.1f;
	}

	if (key->IsPushed(KeyManager::KEY_CODE::LEFT))
	{
		pos.m_x -= 0.1f;
	}
	player->Pos(pos);
}

void PlayerMoveState::Exit(Player* player)
{
}
