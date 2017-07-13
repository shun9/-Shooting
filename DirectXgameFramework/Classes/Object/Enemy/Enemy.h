//************************************************/
//* @file  :Enemy.h
//* @brief :敵クラス
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Enemy : public Object
{
public:
	Enemy();
	~Enemy();

	//更新処理
	void Update()override;

	//状態の切り替え
	void ChangeState(ShunLib::State<Enemy>* state) {
		m_stateMachine->ChangeState(state);
	}

private:
	//状態管理用
	ShunLib::StateMachine<Enemy>* m_stateMachine;
};
