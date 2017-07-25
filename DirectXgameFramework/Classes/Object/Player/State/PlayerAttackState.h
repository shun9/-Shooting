//************************************************/
//* @file  :PlayerAttackState.h
//* @brief :プレイヤーの攻撃中状態
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_State.h>
#include <SL_Timer.h>

class Player;

class PlayerAttackState : public ShunLib::State<Player>
{
private:
	ShunLib::Timer m_timer;

	//撃った後の操作不能時間
	const int m_shootInterval;

public:
	//開始処理
	void Enter(Player* player)override;

	//実行処理
	void Execute(Player* player)override;

	//終了処理
	void Exit(Player* player)override;

public:
	PlayerAttackState() :m_shootInterval(10) {}
	~PlayerAttackState() {}
};