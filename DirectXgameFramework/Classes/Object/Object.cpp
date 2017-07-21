//************************************************/
//* @file  :Object.cpp
//* @brief :�I�u�W�F�N�g�̊��N���X
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#include "Object.h"
#include <SL_Conversion.h>
#include <SL_MacroConstants.h>

/// <summary>
/// �����蔻��
/// </summary>
/// <param name="A">�I�u�W�F�P</param>
/// <param name="B">�I�u�W�F�Q</param>
/// <returns>����</returns>
bool Object::Collision(const Object& A, const Object& B)
{
	using namespace ShunLib;

	Vec3 pos1 = A.Pos();
	Vec3 pos2 = B.Pos();

	float x = pos1.m_x - pos2.m_x;
	float y = pos1.m_z - pos2.m_z;
	float r = A.Radius() + B.Radius();

	if (x*x + y*y <= r*r)
	{
		return true;
	}

	return false;
}

/// <summary>
/// �����蔻��
/// </summary>
/// <param name="A">�I�u�W�F�P(�|�C���^)</param>
/// <param name="B">�I�u�W�F�Q(�|�C���^)</param>
/// <returns>����</returns>
bool Object::Collision(const Object* A, const Object* B)
{
	using namespace ShunLib;

	Vec3 pos1 = A->Pos();
	Vec3 pos2 = B->Pos();

	float x = pos1.m_x - pos2.m_x;
	float y = pos1.m_z - pos2.m_z;
	float r = A->Radius() + B->Radius();

	if (x*x + y*y <= r*r)
	{
		return true;
	}

	return false;
}

//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
//�b�@�\  :�R���X�g���N�^
//�b����  :�摜�̃p�X(wchar_t*)
//�b����  :�������W	 (ShunLib::Vec3)
//�{�[�[�[�[�[�[�[�[�[�[�[�[�[�[�{
Object::Object():
	m_angle(0.0f),
	m_radius(1.0),
	m_model(nullptr),
	m_isDead(false)
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
		Matrix world = Matrix::CreateRotationY(m_angle) * Matrix::CreateTranslation(m_pos);
		m_model->Draw(world, view, proj);
	}
}
