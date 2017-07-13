//************************************************/
//* @file  :PlayScene.h
//* @brief :プレイ画面のヘッダー
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include "Scene.h"
#include <memory>
#include <vector>

/*--[ShunLib]--*/
#include <SL_Matrix.h>
#include <SL_Model.h>

/*--[DirectXTK]--*/
#include <SimpleMath.h>

class Stage;
class Player;
class Enemy;

class PlayScene:public Scene
{
	using MatrixD = DirectX::SimpleMath::Matrix;

public:
	//ステージの横幅
	static const float STAGE_TOP;
	static const float STAGE_BOTTOM;
	static const float STAGE_RIGHT;
	static const float STAGE_LEFT;


private:
	ShunLib::Matrix m_view;	//ビュー行列
	ShunLib::Matrix m_proj;	//プロジェクション行列

	Stage* m_stage;
	Player* m_player;
	Enemy* m_enemy;

public:
	PlayScene();
	~PlayScene();

	//更新＆描画
	void Update()override;
	void Render()override;
};

