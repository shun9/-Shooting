//************************************************/
//* @file  :PlayScene.cpp
//* @brief :プレイ画面のクラス
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#include "PlayScene.h"

/*--[ShunLib]--*/
#include <SL_MacroConstants.h>
#include <SL_ConversionTK.h>
#include <SL_Conversion.h>

#include "../../Graphics.h"
#include "../Stage/Stage.h"

//ステージの上下左右
const float PlayScene::STAGE_TOP = 25.0f;
const float PlayScene::STAGE_BOTTOM = -30.0f;
const float PlayScene::STAGE_RIGHT = 15.0f;
const float PlayScene::STAGE_LEFT = -15.0f;

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//＋ーーーーーーーーーーーーーー＋
PlayScene::PlayScene() {
	//ビュー行列作成
	MatrixD view = MatrixD::CreateLookAt(ConvertTK(Vec3(0.0f, 30.0f, 15.0f)),
										 ConvertTK(Vec3::Zero),
										 ConvertTK(Vec3::UnitY));
	m_view = ConvertTK(view);

	//プロジェクション行列作成
	float w = static_cast<float>(Graphics::Get().Width());
	float h = static_cast<float>(Graphics::Get().Height());
	MatrixD proj = MatrixD::CreatePerspectiveFieldOfView(ToRadian(45.0f),w/h,0.1f,1000.0f);
	m_proj = ConvertTK(proj);

	m_stage = new Stage;

	m_player = new Player;
	m_player->LoadModel(L"CModel\\Player.cmo");
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
PlayScene::~PlayScene()
{
	DELETE_POINTER(m_stage);

	DELETE_POINTER(m_player);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void PlayScene::Update()
{
	m_player->Update();
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :描画処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void PlayScene::Render()
{
	m_stage->Draw(Matrix::Identity, m_view, m_proj);

	m_player->Draw(m_view, m_proj);

}


