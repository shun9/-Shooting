//************************************************/
//* @file  :Object.h
//* @brief :オブジェクトの基底クラス
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
	//識別用タグリスト
	enum TAG_LIST
	{
		PLAYER,
		ENEMY,
		BULLET,
	};

	//オブジェクト同士の当たり判定
	static bool Collision(const Object& A, const Object& B);
	static bool Collision(const Object* A, const Object* B);

protected:
	//モデルデータ
	std::unique_ptr<ShunLib::Model>m_model;

	//位置
	ShunLib::Vec3 m_pos;

	//速度
	ShunLib::Vec3 m_spd;

	//向きの方向
	float m_angle;

	//当たり判定用の半径
	float m_radius;

	//死んだかどうか
	bool m_isDead;

	//識別用タグ
	TAG_LIST m_tag;

public:
	//コンストラクタ＆デストラクタ
	Object();
	Object(const Object& obj);
	virtual ~Object();

	//更新処理
	virtual void Update() = 0;

	//描画処理
	virtual void Draw(const ShunLib::Matrix& view,
					  const ShunLib::Matrix& proj);

	//何かと当たったときの処理
	virtual void Hit(const Object& obj) = 0;

	//範囲外から出ないようにする処理
	virtual void Clamp(float top,float bottom,float right,float left) = 0;

	//位置情報
	const ShunLib::Vec3& Pos()const { return m_pos; }
	void Pos(const ShunLib::Vec3& pos) { m_pos = pos; }

	//速度情報
	const ShunLib::Vec3& Spd()const { return m_spd; }
	void Spd(const ShunLib::Vec3& spd) { m_spd = spd; }

	//当たり判定用の半径
	float Radius()const { return m_radius; }
	void Radius(float radius) { m_radius = radius; }

	//向いている方向への角度
	float Angle()const { return m_angle; }
	void Angle(float angle) { m_angle = angle; }

	//タグ
	TAG_LIST Tag()const { return m_tag; }
	void Tag(TAG_LIST tag) { m_tag = tag; }

	//死んだかどうか
	bool IsDead() { return m_isDead; }

	//モデルの読み込み
	void LoadModel(const wchar_t* model) { m_model = std::make_unique<ShunLib::Model>(model); }
};
