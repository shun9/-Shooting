//************************************************/
//* @file  :Enemy.h
//* @brief :�G�N���X
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_StateMachine.h>
#include "../Object.h"

class Enemy : public Object
{
public:
	static const wchar_t* enemyModel;

private:
	int m_score;

public:
	Enemy();
	Enemy(const Enemy& enemy);
	~Enemy();

	//�X�V����
	void Update()override;

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Enemy>* state) {
		m_stateMachine->ChangeState(state);
	}

	//�e�����������Ƃ��̏���
	void Hit(TAG_LIST tag)override;
	void Clamp(float top, float bottom, float right, float left);

	//���_�擾
	int GetScore() { return m_score; }

	//���_��{�ɂ���
	void ScoreUp() { m_score *= 2; }
private:
	//��ԊǗ��p
	ShunLib::StateMachine<Enemy>* m_stateMachine;
};
