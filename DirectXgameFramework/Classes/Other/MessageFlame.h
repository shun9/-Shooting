//************************************************/
//* @file  :MessageFlame.h
//* @brief :メッセージの枠を表示するクラス
//* @date  :2017/08/01
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Texture.h>
#include <SL_Vec2.h>
#include <SL_MacroConstants.h>

class MessageFlame
{
private:
	using Vec2 = ShunLib::Vec2;
	ShunLib::Texture* m_whiteBoxTexture;
	ShunLib::Texture* m_blackBoxTexture;
	Vec2 m_pos;
	Vec2 m_scale;

public:
	void Draw() {
		m_whiteBoxTexture->Draw(m_pos, m_scale);
		m_blackBoxTexture->Draw(m_pos + Vec2(5.0f,5.0f), Vec2(m_scale.m_x-10.0f,m_scale.m_y-10.0f));
	};

	void Pos(const Vec2& pos)     { m_pos = pos;     }
	Vec2 Pos()                    { return m_pos;    }
	void Scale(const Vec2& scale) { m_scale = scale; }
	Vec2 Scale()                  { return m_scale;  }

	MessageFlame() {
		m_whiteBoxTexture = new ShunLib::Texture(L"Texture\\White.png");
		m_blackBoxTexture = new ShunLib::Texture(L"Texture\\Black.png");
	}
	~MessageFlame() {
		DELETE_POINTER(m_whiteBoxTexture);
		DELETE_POINTER(m_blackBoxTexture);
	}
};