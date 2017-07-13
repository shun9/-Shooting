// Game.h

#pragma once
#ifndef GAME
#define GAME

/*
#include <WinSDKVer.h>
#define _WIN32_WINNT 0x0600
#include <SDKDDKVer.h>
*/

// Use the C++ standard templated min/max
#define NOMINMAX

// DirectX apps don't need GDI
#define NODRAWTEXT
#define NOGDI
#define NOBITMAP

// Include <mcx.h> if you need this
#define NOMCX

// Include <winsvc.h> if you need this
#define NOSERVICE

// WinHelp is deprecated
#define NOHELP


#include <windows.h>
#include <iostream>
#include <string>
#include <iomanip>

#include <d3d11.h>
#include <SimpleMath.h>
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <Model.h>
#include <Keyboard.h>
#include <GeometricPrimitive.h>
#include <WICTextureLoader.h>
#include <algorithm>

#include "StepTimer.h"
#include "dx.h"
#include "Window.h"
#include "Graphics.h"

class Window;

class Game {
public:
	// ��{�Q�[�����[�v�����s���� Run basic game loop
	MSG Run();

	// �R���X�g���N�^ Constructor
    Game(int width, int height);
    // �Q�[���ɕK�v�ȃI�u�W�F�N�g���������� Initialize game object
    virtual void Initialize();
	// �Q�[�����X�V���� Update game
	virtual void Update(DX::StepTimer const& timer);
	// ��ʂ��N���A���� Clear screen
	virtual void Clear();
	// �V�[����`�悷�� Render scene
	virtual void Render(DX::StepTimer const& timer);
	// �o�b�N�o�b�t�@���X�N���[���ɑ���
	virtual void Present();
	// �I�������������Ȃ� Finalize game
	virtual void Finalize();

    // ���b�Z�[�W Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // �v���p�e�B Properties
    void GetDefaultSize(int& width, int& height) const;
	// FPS��`�悷�� Draw FPS
	void DrawFPS();

private:
	// �C���X�^���X�n���h��
	HINSTANCE hInstance;
	// ���s���̃E�B���h�E�̑傫��
	int nCmdShow;
    // �f�o�C�X���\�[�X Device resources
    HWND hWnd;
	// �o�͕� window width
    int width;
	// �o�͍� window height
    int height;

	// �E�B���h�E Window
	std::unique_ptr<Window> window;
	// �O���t�B�b�N�X Graphics
	std::unique_ptr<Graphics> graphics;
	// �@�\���x�� Feature level
    D3D_FEATURE_LEVEL featureLevel;

protected:
    // ���[�v�^�C�}�[��`�悷�� Rendering loop timer
    DX::StepTimer timer;

	// �L�[�{�[�h Keyboard
	std::unique_ptr<DirectX::Keyboard> keyboard;
	// �X�v���C�g�o�b�` SpriteBatch
	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	// �t�H���g Font
	std::unique_ptr<DirectX::SpriteFont> font;
};

#endif	// GAME
