//************************************************/
//* @file  :Bullet.h
//* @brief :ƒvƒŒƒCƒ„[‚Ì”­Ë‚·‚é’eƒNƒ‰ƒX
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Bullet:public Object
{
private:
	//UŒ‚’†‚©‚Ç‚¤‚©
	bool m_isAttackState;

	//Œ‚‚Ä‚éó‘Ô‚©‚Ç‚¤‚©
	bool m_canShoot;

public:
	Bullet();
	~Bullet();

	//ó‘Ô‚ÌØ‚è‘Ö‚¦
	void ChangeState(ShunLib::State<Bullet>* state) {
		m_stateMachine->ChangeState(state);
	}

	//“G‚Æ“–‚½‚Á‚½‚Æ‚«‚Ìˆ—
	void Hit(TAG_LIST tag)override;

	void Clamp(float top, float bottom, float right, float left) override{};

	//UŒ‚’†‚©‚Ç‚¤‚©
	void IsAttackState(bool isAttackState) { m_isAttackState = isAttackState; }
	bool IsAttackState()const { return m_isAttackState; }

	//UŒ‚’†‚©‚Ç‚¤‚©
	void CanShoot(bool canShoot) { m_canShoot = canShoot; }
	bool CanShoot()const { return m_canShoot; }

private:
	//ó‘ÔŠÇ——p
	ShunLib::StateMachine<Bullet>* m_stateMachine;

};