//************************************************/
//* @file  :PlayerCommand.h
//* @brief :プレイヤーのコマンドまとめ
//* @date  :2017/08/03
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Command.h>

class Player;

class PlayerRightMoveCommand :public ShunLib::Command<Player>
{
	void Execute(Player* player)override;
};

class PlayerLeftMoveCommand :public ShunLib::Command<Player>
{
	void Execute(Player* player)override;
};

class PlayerShootCommand :public ShunLib::Command<Player>
{
	void Execute(Player* player)override;
};