//************************************************/
//* @file  :Scene.h
//* @brief :シーンの基底クラス
//* @date  :2017/05/23
//* @author:S.Katou
//************************************************/
#pragma once

class Scene
{
public:
	//シーンの種類
	enum
	{
		TITLE,
		PLAY,
	};

private:
	//現在のシーン
	static int m_currentScene;

protected:
	//次のシーン
	static int m_nextScene;

public:
	//次のシーンを返す
	static int NextScene() { return m_nextScene; }
	static int CurrentScene() { return m_currentScene; }

public:
	virtual ~Scene() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
};

