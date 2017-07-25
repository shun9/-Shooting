//************************************************/
//* @file  :ScoreCounter.h
//* @brief :�X�R�A���J�E���g����N���X
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Singleton.h>
#include <SL_Texture.h>
#include <SL_MacroConstants.h>
#include <SL_Vec2.h>

class ScoreCounter:public ShunLib::Singleton<ScoreCounter>
{
	friend ShunLib::Singleton<ScoreCounter>;

public:
	static const float TEXTURE_WIDTH;
	static const float TEXTURE_HEIGHT;


private:
	//�X�R�A
	int m_score;

	//�����̃e�N�X�`��
	ShunLib::Texture* m_numbers;

	//�\���ʒu
	ShunLib::Vec2 m_pos;

	//�g�嗦
	float m_scale;

public:
	//�X�R�A�����Z�b�g
	void ResetScore() { m_score = 0; }

	//�X�R�A�̎擾
	int GetScore() { return m_score; }

	//�X�R�A�̉��Z
	void AddScore(int score) { m_score += score; }

	//�X�R�A�̕\��
	void DrawScore();

	//������`�悷��
	void DrawNumber(int drawNumber, float x, float y, float scale);

	//�ʒu
	const ShunLib::Vec2& Pos()const { return m_pos; }
	void Pos(const ShunLib::Vec2& pos) { m_pos = pos; }

	//�g�嗦
	float Scale()const { return m_scale; }
	void Scale(float scale) { m_scale = scale; }

private:
	ScoreCounter() :m_score(0) { m_numbers = new ShunLib::Texture(L"Texture\\Numbers.png"); }
	~ScoreCounter() { DELETE_POINTER(m_numbers); }
};
