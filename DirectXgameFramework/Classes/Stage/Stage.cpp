//************************************************/
//* @file  :Stage.cpp
//* @brief :ステージ描画用のクラス
//* @date  :2017/05/14
//* @author:S.Katou
//************************************************/
#include "Stage.h"
#include <SL_MacroConstants.h>

#include "../Scene/PlayScene.h"
Stage::Stage()
{
	using namespace ShunLib;
	m_ground = new Model(L"CModel\\Glass.cmo");
	m_tree = new Model(L"CModel\\tree.cmo");
}

Stage::~Stage()
{
	DELETE_POINTER(m_ground);
	DELETE_POINTER(m_tree);
}

//＋ーーーーーーーーーーーーーー＋
//｜機能  :描画
//｜引数  :ビュー行列		   (ShunLib::Matrix)
//｜引数  :プロジェクション行列(ShunLib::Matrix)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void Stage::Draw(const ShunLib::Matrix& world,
				 const ShunLib::Matrix& view,
				 const ShunLib::Matrix& proj,
				 bool  isDrawTree)
{
	using namespace ShunLib;

	//地面描画
	m_ground->Draw(world, view, proj);

	if (!isDrawTree)
	{
		return;
	}

	//木描画
	for (int i = 0; i < 15; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			Matrix worldLeft = Matrix::CreateTranslation(Vec3(PlayScene::STAGE_LEFT - 3.0f*(j+1), 0.0f, 25.0f - 4 * i));
			Matrix worldRight = Matrix::CreateTranslation(Vec3(PlayScene::STAGE_RIGHT + 3.0f*(j+1), 0.0f, 25.0f - 4 * i));
			m_tree->Draw(worldLeft, view, proj);
			m_tree->Draw(worldRight, view, proj);
		}
	}
}
