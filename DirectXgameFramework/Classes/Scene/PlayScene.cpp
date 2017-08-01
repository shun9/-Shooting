//************************************************/
//* @file  :PlayScene.cpp
//* @brief :�v���C��ʂ̃N���X
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "PlayScene.h"

/*--[ShunLib]--*/
#include <SL_Factory.h>
#include <SL_MacroConstants.h>
#include <SL_ConversionTK.h>
#include <SL_Conversion.h>
#include <SL_RandomNumber.h>
#include <SL_KeyManager.h>

#include "../../Graphics.h"
#include "../Stage/Stage.h"
#include "../Object/Player/Player.h"
#include "../Object/Enemy/Enemy.h"
#include "../Object/Bullet/Bullet.h"
#include "../Other/ScoreCounter.h"
#include "../Other/MessageFlame.h"
#include "SceneMachine.h"
#include "TitleScene.h"

//�X�e�[�W�̏㉺���E
const float PlayScene::STAGE_TOP    =  15.0f;
const float PlayScene::STAGE_BOTTOM = -30.0f;
const float PlayScene::STAGE_RIGHT  =  15.0f;
const float PlayScene::STAGE_LEFT   = -15.0f;

using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
PlayScene::PlayScene() {
	//�r���[�s��쐬
	m_view = Matrix::CreateLookAt(Vec3(0.0f, 30.0f, 15.0f), Vec3::Zero, Vec3::UnitY);

	//�v���W�F�N�V�����s��쐬
	float w = static_cast<float>(Graphics::Get().Width());
	float h = static_cast<float>(Graphics::Get().Height());
	m_proj  = Matrix::CreateProj(ToRadian(45.0f), w / h, 0.1f, 1000.0f);

	//�X�e�[�W����
	m_stage = m_stageFactory.Create();

	//�I�u�W�F�N�g�̏�����
	ObjectInit();

	//UI�̏�����
	UIInit();
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
PlayScene::~PlayScene()
{
	m_playerFactory      .AllDelete();
	m_enemyFactory       .AllDelete();
	m_stageFactory       .AllDelete();
	m_bulletFactory      .AllDelete();
	m_messageFlameFactory.AllDelete();

	m_objectPool  .clear();
	m_objectPool  .shrink_to_fit();
	m_messageFlame.clear();
	m_messageFlame.shrink_to_fit();

	DELETE_POINTER(m_remainingBulletStringTexture);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void PlayScene::Update()
{
	if (!(m_playTimer.IsEnded()))
	{
		ObjectUpdate();

		m_playTimer.Update();
	}
	else
	{
		auto key = KeyManager::GetInstance();

		if (key->IsTracker(KeyManager::KEY_CODE::SPACE))
		{
			SceneMachine::GetInstance()->ChangeScene(new TitleScene);
		}
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�`�揈��
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void PlayScene::Render()
{
	m_stage->Draw(Matrix::Identity, m_view, m_proj);


	//�I�u�W�F�N�g�`�揈��
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end(); itr++)
	{
		if ((*itr) != nullptr)(*itr)->Draw(m_view, m_proj);
	}

	//���b�Z�[�W�t���[���\��
	for (auto itr = m_messageFlame.begin(); itr != m_messageFlame.end(); itr++)
	{
		(*itr)->Draw();
	}

	//�X�R�A�\��
	auto scoreCounter = ScoreCounter::GetInstance();
	scoreCounter->DrawScore();

	//�c��̒e����\��
	m_remainingBulletStringTexture->Draw(500.0f, 548.0f, 1.8f);
	scoreCounter->DrawNumber(m_player->RemainingBulletNum(), 690.0f, 547.0f,1.6f);

	scoreCounter->DrawNumber(m_playTimer.GetRemainingCount()/60, 5.0f, 5.0f, 1.6f);
}

/// <summary>
/// �I�u�W�F�N�g�̏�����
/// </summary>
void PlayScene::ObjectInit()
{
	//�v���C���[�̐���
	m_player = m_playerFactory.Create();
	m_player->LoadModel(L"CModel\\Player.cmo");
	m_objectPool.push_back(m_player);

	//�e�̐���
	for (int i = 0; i < Player::MAX_BULLET; i++)
	{
		auto bullet = m_bulletFactory.Create();
		m_player->RegisterBullet(bullet);
		bullet->Player(m_player);

		bullet->LoadModel(L"CModel\\Ghost.cmo");
		m_objectPool.push_back(bullet);
	}

}

/// <summary>
/// UI�̏�����
/// </summary>
void PlayScene::UIInit()
{
	//�X�R�A�̕\���ݒ�
	auto scoreCounter = ScoreCounter::GetInstance();
	scoreCounter->Pos(Vec2(10.0f, 550.0f));
	scoreCounter->Scale(1.6f);

	//�X�R�A�p���b�Z�[�W�t���[���\���ݒ�
	auto flame = m_messageFlameFactory.Create();
	flame->Pos(Vec2(0.0f, 540.0f));
	flame->Scale(Vec2(800.0f, 60.0f));
	m_messageFlame.push_back(flame);

	//�^�C���p���b�Z�[�W�t���[���\���ݒ�
	flame = m_messageFlameFactory.Create();
	flame->Pos(Vec2(0.0f, 0.0f));
	flame->Scale(Vec2(70.0f, 60.0f));
	m_messageFlame.push_back(flame);

	m_remainingBulletStringTexture = new Texture(L"Texture\\RemainingBulletString.png");

	//���Ԃ̃Z�b�g 60FPS
	m_playTimer.SetTime(60 * 60);

}

/// <summary>
/// �I�u�W�F�N�g�̍X�V
/// </summary>
void PlayScene::ObjectUpdate()
{
	//�X�V����
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end();)
	{
		if ((*itr) != nullptr) {
			(*itr)->Update();
			(*itr)->Clamp(STAGE_TOP, STAGE_BOTTOM, STAGE_RIGHT, STAGE_LEFT);

			//����ł���I�u�W�F�N�g��j��
			if ((*itr)->IsDead()) {
				if (dynamic_cast<Enemy*>((*itr)) != nullptr) {

					m_enemyFactory.Delete(dynamic_cast<Enemy*>((*itr)));
				}
				itr = m_objectPool.erase(itr);
			}
			else {
				itr++;
			}
		}
	}

	//�����蔻��
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end(); itr++)
	{
		for (auto i = itr + 1; i != m_objectPool.end(); i++)
		{
			if (Object::Collision((*i), (*itr)))
			{
				(*itr)->Hit(*(*i));
				(*i)->Hit(*(*itr));
			}
		}
	}
	static int n = 0;
	n++;

	if (n % 100 == 0)
	{
		AppearEnemy();
	}

}

/// <summary>
/// �G�̐���
/// </summary>
void PlayScene::AppearEnemy()
{
	Enemy* enemy = m_enemyFactory.Create();
	enemy->LoadModel(Enemy::enemyModel);

	//���x�Ə����ʒu�������_���Ɍ���
	RandomNumber rn;
	enemy->Pos(Vec3(rn(STAGE_LEFT, STAGE_RIGHT), 0.0f, -20.0f));
	enemy->Spd(Vec3(rn(-15.0f,15.0f), 0.0f, rn(1.0f,10.0f)));

	//�G��ǉ�
	m_objectPool.push_back(enemy);
}
