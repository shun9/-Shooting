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

public:
	//���ʗp�^�O���X�g
	enum TAG_LIST
	{
		PLAYER,
		ENEMY,
		BULLET,
	};

	//�I�u�W�F�N�g���m�̓����蔻��
	static bool Collision(const Object& A, const Object& B);
	static bool Collision(const Object* A, const Object* B);

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

	//���񂾂��ǂ���
	bool m_isDead;

	//���ʗp�^�O
	TAG_LIST m_tag;

public:
	//�R���X�g���N�^���f�X�g���N�^
	Object();
	Object(const Object& obj);
	virtual ~Object();

	//�X�V����
	virtual void Update() = 0;

	//�`�揈��
	virtual void Draw(const ShunLib::Matrix& view,
					  const ShunLib::Matrix& proj);

	//�����Ɠ��������Ƃ��̏���
	virtual void Hit(const Object& obj) = 0;

	//�͈͊O����o�Ȃ��悤�ɂ��鏈��
	virtual void Clamp(float top,float bottom,float right,float left) = 0;

	//�ʒu���
	const ShunLib::Vec3& Pos()const { return m_pos; }
	void Pos(const ShunLib::Vec3& pos) { m_pos = pos; }

	//���x���
	const ShunLib::Vec3& Spd()const { return m_spd; }
	void Spd(const ShunLib::Vec3& spd) { m_spd = spd; }

	//�����蔻��p�̔��a
	float Radius()const { return m_radius; }
	void Radius(float radius) { m_radius = radius; }

	//�����Ă�������ւ̊p�x
	float Angle()const { return m_angle; }
	void Angle(float angle) { m_angle = angle; }

	//�^�O
	TAG_LIST Tag()const { return m_tag; }
	void Tag(TAG_LIST tag) { m_tag = tag; }

	//���񂾂��ǂ���
	bool IsDead() { return m_isDead; }

	//���f���̓ǂݍ���
	void LoadModel(const wchar_t* model) { m_model = std::make_unique<ShunLib::Model>(model); }
};
