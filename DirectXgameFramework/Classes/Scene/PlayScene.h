//************************************************/
//* @file  :PlayScene.h
//* @brief :�v���C��ʂ̃w�b�_�[
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include <memory>
#include <vector>

/*--[ShunLib]--*/
#include <SL_Matrix.h>
#include <SL_Model.h>
#include <SL_Factory.h>
#include <SL_Texture.h>
#include <SL_Timer.h>

#include "Scene.h"

class Stage;
class Object;
class Player;
class Enemy;
class Bullet;
class MessageFlame;

class PlayScene:public Scene
{
public:
	//�X�e�[�W�̉���
	static const float STAGE_TOP;
	static const float STAGE_BOTTOM;
	static const float STAGE_RIGHT;
	static const float STAGE_LEFT;


private:
	ShunLib::Matrix m_view;	//�r���[�s��
	ShunLib::Matrix m_proj;	//�v���W�F�N�V�����s��

	Stage* m_stage;
	Player* m_player;
	ShunLib::Texture* m_remainingBulletStringTexture;
	ShunLib::Texture* m_restartStringTexture;

	//�v���C���Ԃ̃J�E���g�p
	ShunLib::Timer m_playTimer;

	//�G�o���Ԋu�p
	ShunLib::Timer m_appearEnemyTimer;

	//�I�u�W�F�N�g�܂Ƃ�
	std::vector<Object*>m_objectPool;
	std::vector<MessageFlame*> m_messageFlame;

	//�H��Q
	ShunLib::Factory<Player> m_playerFactory;
	ShunLib::Factory<Enemy> m_enemyFactory;
	ShunLib::Factory<Bullet> m_bulletFactory;
	ShunLib::Factory<Stage> m_stageFactory;
	ShunLib::Factory<MessageFlame> m_messageFlameFactory;

public:
	PlayScene();
	~PlayScene();

	//�X�V���`��
	void Update();
	void Render();

private:
	//�I�u�W�F�N�g�̏���������
	void ObjectInit();

	//UI�̏���������
	void UIInit();

	//�I�u�W�F�N�g�̍X�V����
	void ObjectUpdate();

	//�G�̐���
	void AppearEnemy();
};

