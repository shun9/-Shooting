//************************************************/
//* @file  :TitleScene.h
//* @brief :タイトル画面のヘッダー
//* @date  :2017/08/01
//* @author:S.Katou
//************************************************/
#pragma once
#include "Scene.h"

class TitleScene :public Scene
{
private:
public:
	TitleScene();
	~TitleScene();

	//更新＆描画
	void Update()override;
	void Render()override;
};

