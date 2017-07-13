//************************************************/
//* @file  :Object.cpp
//* @brief :�I�u�W�F�N�g�̊��N���X
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "Object.h"
#include <SL_Conversion.h>
#include <SL_MacroConstants.h>

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�摜�̃p�X(wchar_t*)
//�b����  :�������W	 (ShunLib::Vec3)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Object::Object():
	m_angle(0.0f),
	m_model(nullptr)
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�f�X�g���N�^
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Object::~Object()
{

}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�`��
//�b����  :�r���[�s��		   (ShunLib::Matrix)
//�b����  :�v���W�F�N�V�����s��(ShunLib::Matrix)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Object::Draw(const ShunLib::Matrix& view, const ShunLib::Matrix& proj)
{
	using namespace ShunLib;

	if (m_model != nullptr)
	{
		//�����Ă���������v�Z����
		CalculateDirection();

		Matrix world = Matrix::CreateRotationY(m_angle) * Matrix::CreateTranslation(m_pos);
		m_model->Draw(world, view, proj);
	}
}


//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�����Ă���������v�Z����
//�b����  :�Ȃ�(void)
//�b�߂�l:�Ȃ�(void)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
void Object::CalculateDirection()
{
	//�����Ă��Ȃ���Όv�Z���Ȃ�
	if (m_spd.m_x == 0.0f&&m_spd.m_y==0.0f&&m_spd.m_z==0.0f)
	{
		return;
	}

	auto spd = m_spd;
	spd.Normalize();

	float rot = ShunLib::ToAngle(std::atan2(spd.m_z, spd.m_x)) - 90.0f;

	m_angle = rot;
}
