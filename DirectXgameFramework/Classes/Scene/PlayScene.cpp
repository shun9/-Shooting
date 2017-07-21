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

#include "../../Graphics.h"
#include "../Stage/Stage.h"
#include "../Object/Player/Player.h"
#include "../Object/Enemy/Enemy.h"


//�X�e�[�W�̏㉺���E
const float PlayScene::STAGE_TOP = 25.0f;
const float PlayScene::STAGE_BOTTOM = -30.0f;
const float PlayScene::STAGE_RIGHT = 15.0f;
const float PlayScene::STAGE_LEFT = -15.0f;

using namespace ShunLib;

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
PlayScene::PlayScene() {
	//�r���[�s��쐬
	MatrixD view = MatrixD::CreateLookAt(ConvertTK(Vec3(0.0f, 30.0f, 15.0f)),
										 ConvertTK(Vec3::Zero),
										 ConvertTK(Vec3::UnitY));
	m_view = ConvertTK(view);

	//�v���W�F�N�V�����s��쐬
	float w = static_cast<float>(Graphics::Get().Width());
	float h = static_cast<float>(Graphics::Get().Height());
	MatrixD proj = MatrixD::CreatePerspectiveFieldOfView(ToRadian(45.0f),w/h,0.1f,1000.0f);
	m_proj = ConvertTK(proj);

	m_stage = m_stageFactory.Create();

	auto player = m_playerFactory.Create();
	player->LoadModel(L"CModel\\Player.cmo");
	m_objectPool.push_back(player);
	AppearEnemy();
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
PlayScene::~PlayScene()
{
	m_playerFactory.AllDelete();
	m_enemyFactory.AllDelete();
	m_stageFactory.AllDelete();

	m_objectPool.clear();
	m_objectPool.shrink_to_fit();
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void PlayScene::Update()
{
	//�X�V����
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end();)
	{
		if ((*itr) != nullptr) {
			(*itr)->Update();
			(*itr)->Clamp(STAGE_TOP, STAGE_BOTTOM, STAGE_RIGHT, STAGE_LEFT);

			//����ł���I�u�W�F�N�g��j��
			if ((*itr)->IsDead()){
				if (dynamic_cast<Enemy*>((*itr)) != nullptr){
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
		for (auto i = itr+1; i != m_objectPool.end() ; i++)
		{
			if (Object::Collision((*i), (*itr)))
			{
				(*i)->Hit((*itr)->Tag());
				(*itr)->Hit((*i)->Tag());
			}
		}
	}

	static int n = 0;
	n++;

	if (n % 10 == 0)
	{
		AppearEnemy();
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
