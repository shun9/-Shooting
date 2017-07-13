//************************************************/
//* @file  :Object.cpp
//* @brief :オブジェクトの基底クラス
//* @date  :2017/07/13
//* @author:S.Katou
//************************************************/
#include "Object.h"
#include <SL_Conversion.h>
#include <SL_MacroConstants.h>

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :画像のパス(wchar_t*)
//｜引数  :初期座標	 (ShunLib::Vec3)
//＋ーーーーーーーーーーーーーー＋
Object::Object():
	m_angle(0.0f),
	m_model(nullptr)
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
Object::~Object()
{

}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :描画
//｜引数  :ビュー行列		   (ShunLib::Matrix)
//｜引数  :プロジェクション行列(ShunLib::Matrix)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void Object::Draw(const ShunLib::Matrix& view, const ShunLib::Matrix& proj)
{
	using namespace ShunLib;

	if (m_model != nullptr)
	{
		//向いている方向を計算する
		CalculateDirection();

		Matrix world = Matrix::CreateRotationY(m_angle) * Matrix::CreateTranslation(m_pos);
		m_model->Draw(world, view, proj);
	}
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :向いている方向を計算する
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void Object::CalculateDirection()
{
	//動いていなければ計算しない
	if (m_spd.m_x == 0.0f&&m_spd.m_y==0.0f&&m_spd.m_z==0.0f)
	{
		return;
	}

	auto spd = m_spd;
	spd.Normalize();

	float rot = ShunLib::ToAngle(std::atan2(spd.m_z, spd.m_x)) - 90.0f;

	m_angle = rot;
}
