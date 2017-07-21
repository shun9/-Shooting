//************************************************/
//* @file  :Player.h
//* @brief :プレイヤークラス
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once

#include <SL_StateMachine.h>
#include "../Object.h"
class Bullet;

class Player : public Object
{
private:
	//状態管理用
	ShunLib::StateMachine<Player>* m_stateMachine;

	//弾
	std::vector<Bullet*>m_bullet;

public:
	Player();
	~Player();

	//更新処理
	void Update()override;

	//状態の切り替え
	void ChangeState(ShunLib::State<Player>* state) {
		m_stateMachine->ChangeState(state);
	}

	//弾の登録
	void RegisterBullet(Bullet* bullet) {
		m_bullet.push_back(bullet);
	}

	//当たったときの処理
	void Hit(TAG_LIST tag)override;

	//範囲外に出た時の処理
	void Clamp(float top, float bottom, float right, float left);

	void Shoot();

};
