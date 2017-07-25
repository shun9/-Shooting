//************************************************/
//* @file  :ScoreCounter.h
//* @brief :スコアをカウントするクラス
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
	//スコア
	int m_score;

	//数字のテクスチャ
	ShunLib::Texture* m_numbers;

	//表示位置
	ShunLib::Vec2 m_pos;

	//拡大率
	float m_scale;

public:
	//スコアをリセット
	void ResetScore() { m_score = 0; }

	//スコアの取得
	int GetScore() { return m_score; }

	//スコアの加算
	void AddScore(int score) { m_score += score; }

	//スコアの表示
	void DrawScore();

	//数字を描画する
	void DrawNumber(int drawNumber, float x, float y, float scale);

	//位置
	const ShunLib::Vec2& Pos()const { return m_pos; }
	void Pos(const ShunLib::Vec2& pos) { m_pos = pos; }

	//拡大率
	float Scale()const { return m_scale; }
	void Scale(float scale) { m_scale = scale; }

private:
	ScoreCounter() :m_score(0) { m_numbers = new ShunLib::Texture(L"Texture\\Numbers.png"); }
	~ScoreCounter() { DELETE_POINTER(m_numbers); }
};
