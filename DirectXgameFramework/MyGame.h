#pragma once

#ifndef MYGAME
#define MYGAME

#include "Game.h"

#include "Classes\Scene\PlayScene.h"

class MyGame : public Game {
public:
	// �R���X�g���N�^ Constructor
	MyGame(int width, int height);
	// �Q�[���I�u�W�F�N�g���������� Initialize game object
	void Initialize() override;
	// �Q�[�����X�V���� Update game
	void Update(DX::StepTimer const& timer) override;
	// �Q�[���V�[����`�悷�� Draws the scene
	void Render(DX::StepTimer const& timer) override;
	// �I�������������Ȃ� Finalize game
	void Finalize() override;

protected:
	PlayScene* m_scene;

};

#endif	// MYGAME
