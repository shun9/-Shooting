//************************************************/
//* @file  :PlayerMoveState.cpp
//* @brief :�v���C���[�̈ړ����
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "PlayerMoveState.h"

#include <SL_KeyManager.h>
#include "../Player.h"
#include "PlayerAttackState.h"

void PlayerMoveState::Enter(Player * player)
{

}

void PlayerMoveState::Execute(Player* player)
{
	using namespace ShunLib;
	auto key = KeyManager::GetInstance();

	//�L�[��������Ă�����R�}���h���s
	for (auto itr = m_keyList.begin(); itr != m_keyList.end(); itr++)
	{
		if (key->IsPushed((*itr)))
		{
			m_commandInput.HandleInput((*itr))->Execute(player);
		}
	}

	//�X�e�[�g�ؑւ̉\��������̂ŃC�e���[�^���g��Ȃ�
	for (auto i = 0; i < static_cast<int>(m_trackerList.size()); i++)
	{
		if (key->IsPushed(m_trackerList[i]))
		{
			m_commandInputTracker.HandleInput(m_trackerList[i])->Execute(player);
		}
	}
}

void PlayerMoveState::Exit(Player* player)
{
}
