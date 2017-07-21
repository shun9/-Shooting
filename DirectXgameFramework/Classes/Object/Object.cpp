//************************************************/
//* @file  :Object.cpp
//* @brief :オブジェクトの基底クラス
//* @date  :2017/07/18
//* @author:S.Katou
//************************************************/
#include "Object.h"
#include <SL_Conversion.h>
#include <SL_MacroConstants.h>

/// <summary>
/// 当たり判定
/// </summary>
/// <param name="A">オブジェ１</param>
/// <param name="B">オブジェ２</param>
/// <returns>結果</returns>
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
/// 当たり判定
/// </summary>
/// <param name="A">オブジェ１(ポインタ)</param>
/// <param name="B">オブジェ２(ポインタ)</param>
/// <returns>結果</returns>
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

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//｜引数  :画像のパス(wchar_t*)
//｜引数  :初期座標	 (ShunLib::Vec3)
//＋ーーーーーーーーーーーーーー＋
Object::Object():
	m_angle(0.0f),
	m_radius(1.0),
	m_model(nullptr),
	m_isDead(false)
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
		Matrix world = Matrix::CreateRotationY(m_angle) * Matrix::CreateTranslation(m_pos);
		m_model->Draw(world, view, proj);
	}
}
