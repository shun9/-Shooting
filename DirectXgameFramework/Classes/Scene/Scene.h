//************************************************/
//* @file  :Scene.h
//* @brief :�V�[���̊��N���X
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

