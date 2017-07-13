//************************************************/
//* @file  :Object.h
//* @brief :�I�u�W�F�N�g�̊��N���X
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include <map>
#include <memory>
#include <SL_Model.h>
#include <SL_Vec3.h>
#include <SL_Matrix.h>


class Object
{

protected:
	//���f���f�[�^
	std::unique_ptr<ShunLib::Model>m_model;

	//�ʒu
	ShunLib::Vec3 m_pos;

	//���x
	ShunLib::Vec3 m_spd;

	//�����̕���
	float m_angle;

	//�����蔻��p�̔��a
	float m_radius;

public:
	//�R���X�g���N�^���f�X�g���N�^
	Object();
	virtual ~Object();

	//�X�V����
	virtual void Update() = 0;

	//�`�揈��
	virtual void Draw(const ShunLib::Matrix& view,
					  const ShunLib::Matrix& proj);

	//�ʒu���
	ShunLib::Vec3 Pos() { return m_pos; }
	void Pos(const ShunLib::Vec3& pos) { m_pos = pos; }

	//���x���
	ShunLib::Vec3 Spd() { return m_spd; }
	void Spd(const ShunLib::Vec3& spd) { m_spd = spd; }

	//�����蔻��p�̔��a
	void Radius(float radius) { m_radius = radius; }
	float Radius() { return m_radius; }

	//���f���̓ǂݍ���
	void LoadModel(const wchar_t* model) { m_model = std::make_unique<ShunLib::Model>(model); }

protected:
	//�������v�Z����
	void CalculateDirection();
};
