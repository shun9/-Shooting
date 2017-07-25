//************************************************/
//* @file  :ScoreCounter.cpp
//* @brief :スコアをカウントするクラス
//* @date  :2017/07/24
//* @author:S.Katou
//************************************************/
#include "ScoreCounter.h"

#include <deque>

const float ScoreCounter::TEXTURE_WIDTH  = 25;
const float ScoreCounter::TEXTURE_HEIGHT = 27;


/// <summary>
/// スコアの表示
/// </summary>
void ScoreCounter::DrawScore()
{
	DrawNumber(GetScore(), m_pos.m_x, m_pos.m_y, m_scale);
}


/// <summary>
/// 数字を描画
/// </summary>
/// <param name="number">描画する数値</param>
/// <param name="x">表示位置X</param>
/// <param name="y">表示位置X</param>
/// <param name="scale">拡大率</param>
void ScoreCounter::DrawNumber(int drawNumber, float x, float y, float scale)
{
	std::deque<int>decomposedNumber;

	//数字を各桁ごとに分解する
	while (drawNumber > 0)
	{
		//一番下の桁の数字を取り出す
		decomposedNumber.push_front(drawNumber % 10);

		//桁を一つ下げる
		drawNumber /= 10;
	}

	//空なら０を表示
	if (decomposedNumber.empty()) { decomposedNumber.push_back(0); }

	//描画
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

