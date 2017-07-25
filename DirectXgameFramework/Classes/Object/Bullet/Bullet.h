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

	//�߂��Ă���r�����ǂ���
	bool m_isReturnState;

	//�ҋ@�����ǂ���
	bool m_isStandState;

	//���̒e�����v���C���[
	Object* m_player;

public:
	Bullet();
	~Bullet();

	void Update()override;

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Bullet>* state) {
		m_stateMachine->ChangeState(state);
	}

	//�G�Ɠ��������Ƃ��̏���
	void Hit(const Object& obj)override;

	//�͈͊O�ɏo�����̏���
	void Clamp(float top, float bottom, float right, float left) override;

	//�U�������ǂ���
	void IsAttackState(bool isAttackState) { m_isAttackState = isAttackState; }
	bool IsAttackState()const { return m_isAttackState; }

	//�߂��Ă���r�����ǂ���
	void IsReturnState(bool isReturnState) { m_isReturnState = isReturnState; }
	bool IsReturnState()const { return m_isReturnState; }

	//�ҋ@�����ǂ���
	void IsStandState(bool isStandState) { m_isStandState = isStandState; }
	bool IsStandState()const { return m_isStandState; }

	//���̒e�����v���C���[
	void Player(Object* player) { m_player = player; }
	Object* Player()const { return m_player; }

	//����
	void Shoot();

private:
	//��ԊǗ��p
	ShunLib::StateMachine<Bullet>* m_stateMachine;

};