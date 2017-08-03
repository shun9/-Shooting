//************************************************/
//* @file  :PlayerMoveState.h
//* @brief :プレイヤーの移動状態
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_CommandInput.h>
#include <SL_KeyManager.h>

#include "../Command/PlayerCommand.h"

class Player;

class PlayerMoveState : public ShunLib::State<Player>
{
private:
	ShunLib::CommandInput<ShunLib::KeyManager::KEY_CODE, Player>m_commandInput;
	ShunLib::CommandInput<ShunLib::KeyManager::KEY_CODE, Player>m_commandInputTracker;
	std::vector<ShunLib::KeyManager::KEY_CODE>m_keyList;
	std::vector<ShunLib::KeyManager::KEY_CODE>m_trackerList;

public:
	//開始処理
	void Enter(Player* player)override;

	//実行処理
	void Execute(Player* player)override;

	//終了処理
	void Exit(Player* player)override;

	PlayerMoveState() {
		using namespace ShunLib;

		m_commandInput.SetCommand(KeyManager::KEY_CODE::LEFT, new PlayerLeftMoveCommand);
		m_commandInput.SetCommand(KeyManager::KEY_CODE::RIGHT, new PlayerRightMoveCommand);
		m_commandInputTracker.SetCommand(KeyManager::KEY_CODE::SPACE, new PlayerShootCommand);
		m_keyList = m_commandInput.GetKeyList();
		m_trackerList = m_commandInputTracker.GetKeyList();
	}
	~PlayerMoveState() {}
};