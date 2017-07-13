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

public:
	//コンストラクタ＆デストラクタ
	Object();
	virtual ~Object();

	//更新処理
	virtual void Update() = 0;

	//描画処理
	virtual void Draw(const ShunLib::Matrix& view,
					  const ShunLib::Matrix& proj);

	//位置情報
	ShunLib::Vec3 Pos() { return m_pos; }
	void Pos(const ShunLib::Vec3& pos) { m_pos = pos; }

	//速度情報
	ShunLib::Vec3 Spd() { return m_spd; }
	void Spd(const ShunLib::Vec3& spd) { m_spd = spd; }

	//当たり判定用の半径
	void Radius(float radius) { m_radius = radius; }
	float Radius() { return m_radius; }

	//モデルの読み込み
	void LoadModel(const wchar_t* model) { m_model = std::make_unique<ShunLib::Model>(model); }

protected:
	//向きを計算する
	void CalculateDirection();
};
