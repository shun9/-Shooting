//************************************************/
//* @file  :Enemy.h
//* @brief :�G�N���X
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

	//�X�V����
	void Update()override;

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Enemy>* state) {
		m_stateMachine->ChangeState(state);
	}

private:
	//��ԊǗ��p
	ShunLib::StateMachine<Enemy>* m_stateMachine;
};
