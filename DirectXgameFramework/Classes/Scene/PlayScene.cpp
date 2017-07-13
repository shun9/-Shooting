//************************************************/
//* @file  :PlayScene.cpp
//* @brief :�v���C��ʂ̃N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#include "PlayScene.h"

/*--[ShunLib]--*/
#include <SL_MacroConstants.h>
#include <SL_ConversionTK.h>
#include <SL_Conversion.h>

#include "../../Graphics.h"
#include "../Stage/Stage.h"

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

	m_stage = new Stage;

	m_player = new Player;
	m_player->LoadModel(L"CModel\\Player.cmo");
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
PlayScene::~PlayScene()
{
	DELETE_POINTER(m_stage);

	DELETE_POINTER(m_player);
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�X�V����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void PlayScene::Update()
{
	m_player->Update();
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�`�揈��
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void PlayScene::Render()
{
	m_stage->Draw(Matrix::Identity, m_view, m_proj);

	m_player->Draw(m_view, m_proj);

}


