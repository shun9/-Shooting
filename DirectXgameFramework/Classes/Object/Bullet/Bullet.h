//************************************************/
//* @file  :Bullet.h
//* @brief :�v���C���[�̔��˂���e�N���X
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Bullet:public Object
{
private:
	//�U�������ǂ���
	bool m_isAttackState;

	//���Ă��Ԃ��ǂ���
	bool m_canShoot;

public:
	Bullet();
	~Bullet();

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Bullet>* state) {
		m_stateMachine->ChangeState(state);
	}

	//�G�Ɠ��������Ƃ��̏���
	void Hit(TAG_LIST tag)override;

	void Clamp(float top, float bottom, float right, float left) override{};

	//�U�������ǂ���
	void IsAttackState(bool isAttackState) { m_isAttackState = isAttackState; }
	bool IsAttackState()const { return m_isAttackState; }

	//�U�������ǂ���
	void CanShoot(bool canShoot) { m_canShoot = canShoot; }
	bool CanShoot()const { return m_canShoot; }

private:
	//��ԊǗ��p
	ShunLib::StateMachine<Bullet>* m_stateMachine;

};