//************************************************/
//* @file  :Player.h
//* @brief :プレイヤークラス
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once

#include <SL_StateMachine.h>
#include "../Object.h"

class Player : public Object
{
public:
	Player();
	~Player();

	//更新処理
	void Update()override;

	//状態の切り替え
	void ChangeState(ShunLib::State<Player>* state) {
		m_stateMachine->ChangeState(state);
	}

private:
	//状態管理用
	ShunLib::StateMachine<Player>* m_stateMachine;

};
