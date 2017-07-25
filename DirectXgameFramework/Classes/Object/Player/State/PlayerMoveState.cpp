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
	auto pos = player->Pos();

	//���E�L�[�ŉ��ړ�
	if (key->IsPushed(KeyManager::KEY_CODE::RIGHT))
	{
		pos.m_x += (player->Spd().m_x /60.0f);
	}

	if (key->IsPushed(KeyManager::KEY_CODE::LEFT))
	{
		pos.m_x -= player->Spd().m_x / 60.0f;
	}
	player->Pos(pos);

	//�X�y�[�X�L�[�������ꂽ��e������
	if (key->IsTracker(KeyManager::KEY_CODE::SPACE))
	{
		player->ChangeState(new PlayerAttackState);
	}
}

void PlayerMoveState::Exit(Player* player)
{
}
