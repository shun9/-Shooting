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

	//撃てる状態かどうか
	bool m_canShoot;

public:
	Bullet();
	~Bullet();

	//状態の切り替え
	void ChangeState(ShunLib::State<Bullet>* state) {
		m_stateMachine->ChangeState(state);
	}

	//敵と当たったときの処理
	void Hit(TAG_LIST tag)override;

	void Clamp(float top, float bottom, float right, float left) override{};

	//攻撃中かどうか
	void IsAttackState(bool isAttackState) { m_isAttackState = isAttackState; }
	bool IsAttackState()const { return m_isAttackState; }

	//攻撃中かどうか
	void CanShoot(bool canShoot) { m_canShoot = canShoot; }
	bool CanShoot()const { return m_canShoot; }

private:
	//状態管理用
	ShunLib::StateMachine<Bullet>* m_stateMachine;

};