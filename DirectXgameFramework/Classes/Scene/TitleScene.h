//************************************************/
//* @file  :TitleScene.h
//* @brief :�^�C�g����ʂ̃w�b�_�[
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

	//�X�V���`��
	void Update()override;
	void Render()override;
};

