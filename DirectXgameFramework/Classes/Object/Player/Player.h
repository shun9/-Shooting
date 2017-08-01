//************************************************/
//* @file  :Player.h
//* @brief :�v���C���[�N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once

#include <SL_StateMachine.h>
#include "../Object.h"
class Bullet;

class Player : public Object
{
public:
	static const int MAX_BULLET;

private:
	//��ԊǗ��p
	ShunLib::StateMachine<Player>* m_stateMachine;

	//�e
	std::vector<Bullet*>m_bullet;

public:
	Player();
	~Player();

	//�X�V����
	void Update()override;

	//��Ԃ̐؂�ւ�
	void ChangeState(ShunLib::State<Player>* state) {
		m_stateMachine->ChangeState(state);
	}

	//�e�̓o�^
	void RegisterBullet(Bullet* bullet) {
		m_bullet.push_back(bullet);
	}

	//���������Ƃ��̏���
	void Hit(const Object& obj)override;

	//�͈͊O�ɏo�����̏���
	void Clamp(float top, float bottom, float right, float left);

	//�e������
	void Shoot();

	//�c��̒e�����J�E���g
	int RemainingBulletNum();
};
