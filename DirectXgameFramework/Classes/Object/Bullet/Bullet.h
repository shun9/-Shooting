//************************************************/
//* @file  :Bullet.h
//* @brief :プレイヤーの発射する弾クラス
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Bullet:public Object
{
private:
	//攻撃中かどうか
	bool m_isAttackState;

	//戻ってくる途中かどうか
	bool m_isReturnState;

	//待機中かどうか
	bool m_isStandState;

	//この弾を撃つプレイヤー
	Object* m_player;

public:
	Bullet();
	~Bullet();

	void Update()override;

	//状態の切り替え
	void ChangeState(ShunLib::State<Bullet>* state) {
		m_stateMachine->ChangeState(state);
	}

	//敵と当たったときの処理
	void Hit(const Object& obj)override;

	//範囲外に出た時の処理
	void Clamp(float top, float bottom, float right, float left) override;

	//攻撃中かどうか
	void IsAttackState(bool isAttackState) { m_isAttackState = isAttackState; }
	bool IsAttackState()const { return m_isAttackState; }

	//戻ってくる途中かどうか
	void IsReturnState(bool isReturnState) { m_isReturnState = isReturnState; }
	bool IsReturnState()const { return m_isReturnState; }

	//待機中かどうか
	void IsStandState(bool isStandState) { m_isStandState = isStandState; }
	bool IsStandState()const { return m_isStandState; }

	//この弾を撃つプレイヤー
	void Player(Object* player) { m_player = player; }
	Object* Player()const { return m_player; }

	//撃つ
	void Shoot();

private:
	//状態管理用
	ShunLib::StateMachine<Bullet>* m_stateMachine;

};