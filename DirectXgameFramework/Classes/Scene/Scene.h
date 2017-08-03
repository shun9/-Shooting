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
	virtual ~Scene() {}
	virtual void Update() = 0;
	virtual void Render() = 0;
};

