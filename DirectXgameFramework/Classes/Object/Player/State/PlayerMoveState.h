//************************************************/
//* @file  :PlayerMoveState.h
//* @brief :プレイヤーの移動状態
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_Singleton.h>
#include "../Player.h"

class PlayerMoveState : public ShunLib::State<Player>
{
public:
	//開始処理
	void Enter(Player* player)override;

	//実行処理
	void Execute(Player* player)override;

	//終了処理
	void Exit(Player* player)override;

public:
	PlayerMoveState() {}
	~PlayerMoveState() {}
};