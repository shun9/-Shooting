//************************************************/
//* @file  :Enemy.h
//* @brief :敵クラス
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Enemy : public Object
{
public:
	static const wchar_t* enemyModel;

private:
	int m_score;

public:
	Enemy();
	Enemy(const Enemy& enemy);
	~Enemy();

	//更新処理
	void Update()override;

	//状態の切り替え
	void ChangeState(ShunLib::State<Enemy>* state) {
		m_stateMachine->ChangeState(state);
	}

	//弾が当たったときの処理
	void Hit(TAG_LIST tag)override;
	void Clamp(float top, float bottom, float right, float left);

	//得点取得
	int GetScore() { return m_score; }

	//得点を倍にする
	void ScoreUp() { m_score *= 2; }
private:
	//状態管理用
	ShunLib::StateMachine<Enemy>* m_stateMachine;
};
