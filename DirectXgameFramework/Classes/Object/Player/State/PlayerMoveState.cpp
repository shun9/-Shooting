//************************************************/
//* @file  :PlayerMoveState.cpp
//* @brief :プレイヤーの移動状態
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "PlayerMoveState.h"

#include <SL_KeyManager.h>
#include "../Player.h"
#include "PlayerAttackState.h"

void PlayerMoveState::Enter(Player * player)
{

}

void PlayerMoveState::Execute(Player* player)
{
	using namespace ShunLib;
	auto key = KeyManager::GetInstance();
	auto pos = player->Pos();

	//左右キーで横移動
	if (key->IsPushed(KeyManager::KEY_CODE::RIGHT))
	{
		pos.m_x += (player->Spd().m_x /60.0f);
	}

	if (key->IsPushed(KeyManager::KEY_CODE::LEFT))
	{
		pos.m_x -= player->Spd().m_x / 60.0f;
	}
	player->Pos(pos);

	//スペースキーが押されたら弾を撃つ
	if (key->IsTracker(KeyManager::KEY_CODE::SPACE))
	{
		player->ChangeState(new PlayerAttackState);
	}
}

void PlayerMoveState::Exit(Player* player)
{
}
