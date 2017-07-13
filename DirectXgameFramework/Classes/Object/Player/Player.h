//************************************************/
//* @file  :Player.h
//* @brief :�v���C���[�N���X
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

	//�X�V����
	void Update()override;

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Player>* state) {
		m_stateMachine->ChangeState(state);
	}

private:
	//��ԊǗ��p
	ShunLib::StateMachine<Player>* m_stateMachine;

};
