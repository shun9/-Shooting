//************************************************/
//* @file  :SceneMachine.h
//* @brief :�V�[�����Ǘ�����N���X
//* @date  :2017/08/01
//* @author:S.Katou
//************************************************/
#pragma once
#include <SL_Singleton.h>
#include <SL_MacroConstants.h>
#include "Scene.h"

class SceneMachine:public ShunLib::Singleton<SceneMachine>
{
	friend ShunLib::Singleton<SceneMachine>;

private:
	Scene* m_currentScene;

public:
	void Update() { m_currentScene->Update(); }
	void Render() { m_currentScene->Render(); }

	//�V�[���̐؂�ւ�
	void ChangeScene(Scene* nextScene) {
		DELETE_POINTER(m_currentScene);
		m_currentScene = nextScene;
	}

private:
	SceneMachine() :m_currentScene(nullptr){}
	~SceneMachine() { DELETE_POINTER(m_currentScene); }
};