//************************************************/
//* @file  :PlayerAttackState.cpp
//* @brief :�v���C���[�̍U�������
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#include "PlayerAttackState.h"
#include "../Player.h"
#include "PlayerMoveState.h"
void PlayerAttackState::Enter(Player * player)
{
	//�e������
	player->Shoot();

	//�v�����鎞�Ԃ�ݒ�
	m_timer.SetTime(m_shootInterval);

	//�J�E���g��������
	m_timer.ResetCount();
}

void PlayerAttackState::Execute(Player * player)
{
	//���Ԍv��
	m_timer.Update();

	//���Ԃ��o�߂�����؂�ւ�
	if (m_timer.IsEnded())
	{
		player->ChangeState(new PlayerMoveState);
	}
}

void PlayerAttackState::Exit(Player * player)
{
}
