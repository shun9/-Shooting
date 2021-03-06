//************************************************/
//* @file  :Stage.h
//* @brief :ステージ描画用のクラス
//* @date  :2017/07/10
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Model.h>
#include <SL_Texture.h>

class Stage
{
private:
	//地面と木のモデル
	ShunLib::Model* m_ground;
	ShunLib::Model* m_tree;

public:
	Stage();
	~Stage();

	//描画
	void Draw(const ShunLib::Matrix& world,
			  const ShunLib::Matrix& view,
			  const ShunLib::Matrix& proj,
			  bool  isDrawTree = true);
};