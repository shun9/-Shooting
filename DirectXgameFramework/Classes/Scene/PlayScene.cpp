//************************************************/
//* @file  :PlayScene.cpp
//* @brief :プレイ画面のクラス
//* @date  :2017/07/21
//* @author:S.Katou
//************************************************/
#include "PlayScene.h"

/*--[ShunLib]--*/
#include <SL_Factory.h>
#include <SL_MacroConstants.h>
#include <SL_ConversionTK.h>
#include <SL_Conversion.h>
#include <SL_RandomNumber.h>
#include <SL_KeyManager.h>

#include "../../Graphics.h"
#include "../Stage/Stage.h"
#include "../Object/Player/Player.h"
#include "../Object/Enemy/Enemy.h"
#include "../Object/Bullet/Bullet.h"
#include "../Other/ScoreCounter.h"
#include "../Other/MessageFlame.h"
#include "SceneMachine.h"
#include "TitleScene.h"

//ステージの上下左右
const float PlayScene::STAGE_TOP    =  15.0f;
const float PlayScene::STAGE_BOTTOM = -30.0f;
const float PlayScene::STAGE_RIGHT  =  15.0f;
const float PlayScene::STAGE_LEFT   = -15.0f;

using namespace ShunLib;

//＋ーーーーーーーーーーーーーー＋
//｜機能  :コンストラクタ
//＋ーーーーーーーーーーーーーー＋
PlayScene::PlayScene() {
	//ビュー行列作成
	m_view = Matrix::CreateLookAt(Vec3(0.0f, 30.0f, 15.0f), Vec3::Zero, Vec3::UnitY);

	//プロジェクション行列作成
	float w = static_cast<float>(Graphics::Get().Width());
	float h = static_cast<float>(Graphics::Get().Height());
	m_proj  = Matrix::CreateProj(ToRadian(45.0f), w / h, 0.1f, 1000.0f);

	//ステージ生成
	m_stage = m_stageFactory.Create();

	//オブジェクトの初期化
	ObjectInit();

	//UIの初期化
	UIInit();
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :デストラクタ
//＋ーーーーーーーーーーーーーー＋
PlayScene::~PlayScene()
{
	m_playerFactory      .AllDelete();
	m_enemyFactory       .AllDelete();
	m_stageFactory       .AllDelete();
	m_bulletFactory      .AllDelete();
	m_messageFlameFactory.AllDelete();

	m_objectPool  .clear();
	m_objectPool  .shrink_to_fit();
	m_messageFlame.clear();
	m_messageFlame.shrink_to_fit();

	DELETE_POINTER(m_remainingBulletStringTexture);
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :更新処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void PlayScene::Update()
{
	if (!(m_playTimer.IsEnded()))
	{
		ObjectUpdate();

		m_playTimer.Update();
	}
	else
	{
		auto key = KeyManager::GetInstance();

		if (key->IsTracker(KeyManager::KEY_CODE::SPACE))
		{
			SceneMachine::GetInstance()->ChangeScene(new TitleScene);
		}
	}
}


//＋ーーーーーーーーーーーーーー＋
//｜機能  :描画処理
//｜引数  :なし(void)
//｜戻り値:なし(void)
//＋ーーーーーーーーーーーーーー＋
void PlayScene::Render()
{
	m_stage->Draw(Matrix::Identity, m_view, m_proj);


	//オブジェクト描画処理
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end(); itr++)
	{
		if ((*itr) != nullptr)(*itr)->Draw(m_view, m_proj);
	}

	//メッセージフレーム表示
	for (auto itr = m_messageFlame.begin(); itr != m_messageFlame.end(); itr++)
	{
		(*itr)->Draw();
	}

	//スコア表示
	auto scoreCounter = ScoreCounter::GetInstance();
	scoreCounter->DrawScore();

	//残りの弾数を表示
	m_remainingBulletStringTexture->Draw(500.0f, 548.0f, 1.8f);
	scoreCounter->DrawNumber(m_player->RemainingBulletNum(), 690.0f, 547.0f,1.6f);

	scoreCounter->DrawNumber(m_playTimer.GetRemainingCount()/60, 5.0f, 5.0f, 1.6f);
}

/// <summary>
/// オブジェクトの初期化
/// </summary>
void PlayScene::ObjectInit()
{
	//プレイヤーの生成
	m_player = m_playerFactory.Create();
	m_player->LoadModel(L"CModel\\Player.cmo");
	m_objectPool.push_back(m_player);

	//弾の生成
	for (int i = 0; i < Player::MAX_BULLET; i++)
	{
		auto bullet = m_bulletFactory.Create();
		m_player->RegisterBullet(bullet);
		bullet->Player(m_player);

		bullet->LoadModel(L"CModel\\Ghost.cmo");
		m_objectPool.push_back(bullet);
	}

}

/// <summary>
/// UIの初期化
/// </summary>
void PlayScene::UIInit()
{
	//スコアの表示設定
	auto scoreCounter = ScoreCounter::GetInstance();
	scoreCounter->Pos(Vec2(10.0f, 550.0f));
	scoreCounter->Scale(1.6f);

	//スコア用メッセージフレーム表示設定
	auto flame = m_messageFlameFactory.Create();
	flame->Pos(Vec2(0.0f, 540.0f));
	flame->Scale(Vec2(800.0f, 60.0f));
	m_messageFlame.push_back(flame);

	//タイム用メッセージフレーム表示設定
	flame = m_messageFlameFactory.Create();
	flame->Pos(Vec2(0.0f, 0.0f));
	flame->Scale(Vec2(70.0f, 60.0f));
	m_messageFlame.push_back(flame);

	m_remainingBulletStringTexture = new Texture(L"Texture\\RemainingBulletString.png");

	//時間のセット 60FPS
	m_playTimer.SetTime(60 * 60);

}

/// <summary>
/// オブジェクトの更新
/// </summary>
void PlayScene::ObjectUpdate()
{
	//更新処理
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end();)
	{
		if ((*itr) != nullptr) {
			(*itr)->Update();
			(*itr)->Clamp(STAGE_TOP, STAGE_BOTTOM, STAGE_RIGHT, STAGE_LEFT);

			//死んでいるオブジェクトを破棄
			if ((*itr)->IsDead()) {
				if (dynamic_cast<Enemy*>((*itr)) != nullptr) {

					m_enemyFactory.Delete(dynamic_cast<Enemy*>((*itr)));
				}
				itr = m_objectPool.erase(itr);
			}
			else {
				itr++;
			}
		}
	}

	//当たり判定
	for (auto itr = m_objectPool.begin(); itr != m_objectPool.end(); itr++)
	{
		for (auto i = itr + 1; i != m_objectPool.end(); i++)
		{
			if (Object::Collision((*i), (*itr)))
			{
				(*itr)->Hit(*(*i));
				(*i)->Hit(*(*itr));
			}
		}
	}
	static int n = 0;
	n++;

	if (n % 100 == 0)
	{
		AppearEnemy();
	}

}

/// <summary>
/// 敵の生成
/// </summary>
void PlayScene::AppearEnemy()
{
	Enemy* enemy = m_enemyFactory.Create();
	enemy->LoadModel(Enemy::enemyModel);

	//速度と初期位置をランダムに決定
	RandomNumber rn;
	enemy->Pos(Vec3(rn(STAGE_LEFT, STAGE_RIGHT), 0.0f, -20.0f));
	enemy->Spd(Vec3(rn(-15.0f,15.0f), 0.0f, rn(1.0f,10.0f)));

	//敵を追加
	m_objectPool.push_back(enemy);
}
