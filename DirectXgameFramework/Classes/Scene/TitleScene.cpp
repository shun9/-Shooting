//************************************************/
//* @file  :TitleScene.cpp
//* @brief :ƒ^ƒCƒgƒ‹‰æ–Ê
//* @date  :2017/08/01
//* @author:S.Katou
//************************************************/
#include "TitleScene.h"
#include <SL_KeyManager.h>
#include "../Other/ScoreCounter.h"
#include "SceneMachine.h"
#include "PlayScene.h"

using namespace ShunLib;

TitleScene::TitleScene()
{

}


TitleScene::~TitleScene()
{

}

void TitleScene::Update()
{
	auto key = KeyManager::GetInstance();

	if (key->IsTracker(KeyManager::KEY_CODE::SPACE))
	{
		SceneMachine::GetInstance()->ChangeScene(new PlayScene);
	}
}

void TitleScene::Render()
{

}
