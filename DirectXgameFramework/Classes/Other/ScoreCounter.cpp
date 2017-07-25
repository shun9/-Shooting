//************************************************/
//* @file  :ScoreCounter.cpp
//* @brief :�X�R�A���J�E���g����N���X
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#include "ScoreCounter.h"

#include <deque>

const float ScoreCounter::TEXTURE_WIDTH  = 25;
const float ScoreCounter::TEXTURE_HEIGHT = 27;


/// <summary>
/// �X�R�A�̕\��
/// </summary>
void ScoreCounter::DrawScore()
{
	DrawNumber(GetScore(), m_pos.m_x, m_pos.m_y, m_scale);
}


/// <summary>
/// ������`��
/// </summary>
/// <param name="number">�`�悷�鐔�l</param>
/// <param name="x">�\���ʒuX</param>
/// <param name="y">�\���ʒuX</param>
/// <param name="scale">�g�嗦</param>
void ScoreCounter::DrawNumber(int drawNumber, float x, float y, float scale)
{
	std::deque<int>decomposedNumber;

	//�������e�����Ƃɕ�������
	while (drawNumber > 0)
	{
		//��ԉ��̌��̐��������o��
		decomposedNumber.push_front(drawNumber % 10);

		//�����������
		drawNumber /= 10;
	}

	//��Ȃ�O��\��
	if (decomposedNumber.empty()) { decomposedNumber.push_back(0); }

	//�`��
	for (auto i = 0; i < static_cast<int>(decomposedNumber.size()); i++)
	{
		int num = decomposedNumber[i];

		RECT rect = { TEXTURE_WIDTH * num,
					  0,
					  TEXTURE_WIDTH * (num+1),
					  TEXTURE_HEIGHT };

		m_numbers->Draw(x + (TEXTURE_WIDTH * i), y, scale, &rect);
	}
}

