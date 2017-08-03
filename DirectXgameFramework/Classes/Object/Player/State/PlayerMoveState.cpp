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

	//キーが押されていたらコマンド実行
	for (auto itr = m_keyList.begin(); itr != m_keyList.end(); itr++)
	{
		if (key->IsPushed((*itr)))
		{
			m_commandInput.HandleInput((*itr))->Execute(player);
		}
	}

	//ステート切替の可能性があるのでイテレータを使わない
	for (auto i = 0; i < static_cast<int>(m_trackerList.size()); i++)
	{
		if (key->IsPushed(m_trackerList[i]))
		{
			m_commandInputTracker.HandleInput(m_trackerList[i])->Execute(player);
		}
	}
}

void PlayerMoveState::Exit(Player* player)
{
}
