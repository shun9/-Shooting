//************************************************/
//* @file  :PlayScene.h
//* @brief :プレイ画面のヘッダー
//* @date  :2017/07/12
//* @author:S.Katou
//************************************************/
#pragma once
#include <memory>
#include <vector>

/*--[ShunLib]--*/
#include <SL_Matrix.h>
#include <SL_Model.h>
#include <SL_Factory.h>
#include <SL_Texture.h>
#include <SL_Timer.h>

#include "Scene.h"

class Stage;
class Object;
class Player;
class Enemy;
class Bullet;
class MessageFlame;

class PlayScene:public Scene
{
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
	ShunLib::Texture* m_remainingBulletStringTexture;
	ShunLib::Texture* m_restartStringTexture;

	//プレイ時間のカウント用
	ShunLib::Timer m_playTimer;

	//敵出現間隔用
	ShunLib::Timer m_appearEnemyTimer;

	//オブジェクトまとめ
	std::vector<Object*>m_objectPool;
	std::vector<MessageFlame*> m_messageFlame;

	//工場群
	ShunLib::Factory<Player> m_playerFactory;
	ShunLib::Factory<Enemy> m_enemyFactory;
	ShunLib::Factory<Bullet> m_bulletFactory;
	ShunLib::Factory<Stage> m_stageFactory;
	ShunLib::Factory<MessageFlame> m_messageFlameFactory;

public:
	PlayScene();
	~PlayScene();

	//更新＆描画
	void Update();
	void Render();

private:
	//オブジェクトの初期化処理
	void ObjectInit();

	//UIの初期化処理
	void UIInit();

	//オブジェクトの更新処理
	void ObjectUpdate();

	//敵の生成
	void AppearEnemy();
};

