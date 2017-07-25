//************************************************/
//* @file  :PlayerAttackState.cpp
//* @brief :プレイヤーの攻撃中状態
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#include "PlayerAttackState.h"
#include "../Player.h"
#include "PlayerMoveState.h"
void PlayerAttackState::Enter(Player * player)
{
	//弾を撃つ
	player->Shoot();

	//計測する時間を設定
	m_timer.SetTime(m_shootInterval);

	//カウントを初期化
	m_timer.ResetCount();
}

void PlayerAttackState::Execute(Player * player)
{
	//時間計測
	m_timer.Update();

	//時間が経過したら切り替え
	if (m_timer.IsEnded())
	{
		player->ChangeState(new PlayerMoveState);
	}
}

void PlayerAttackState::Exit(Player * player)
{
}
