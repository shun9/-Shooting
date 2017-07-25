//************************************************/
//* @file  :PlayScene.h
//* @brief :�v���C��ʂ̃w�b�_�[
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include "Scene.h"
#include <memory>
#include <vector>

/*--[ShunLib]--*/
#include <SL_Matrix.h>
#include <SL_Model.h>
#include <SL_Factory.h>

/*--[DirectXTK]--*/
#include <SimpleMath.h>

class Stage;
class Object;
class Player;
class Enemy;
class Bullet;

class PlayScene:public Scene
{
	using MatrixD = DirectX::SimpleMath::Matrix;

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

	std::vector<Object*>m_objectPool;

	ShunLib::Factory<Player> m_playerFactory;
	ShunLib::Factory<Enemy> m_enemyFactory;
	ShunLib::Factory<Bullet> m_bulletFactory;
	ShunLib::Factory<Stage> m_stageFactory;

public:
	PlayScene();
	~PlayScene();

	//�X�V���`��
	void Update()override;
	void Render()override;

private:
	//�G�̐���
	void AppearEnemy();
};

