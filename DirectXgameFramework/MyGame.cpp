#include "MyGame.h"

/*--[ShunLib]--*/
#include <SL_MacroConstants.h>
#include <SL_Model.h>
#include <SL_Texture.h>
#include <SL_Effect.h>
#include <SL_KeyManager.h>

using namespace Microsoft;
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// �R���X�g���N�^ Constructor
MyGame::MyGame(int width, int height) : Game(width, height){
}

// MyGame�I�u�W�F�N�g���������� Initialize MyGame object
void MyGame::Initialize() {
	// ��{�N���X��Initialize���Ăяo��
	Game::Initialize();

	//�f�o�C�X�ݒ�
	Graphics* graph = &(Graphics::Get());
	ShunLib::Model::SetDevice  (graph->Device(), graph->Context());
	ShunLib::Texture::SetDevice(graph->Device(), graph->Context());
	ShunLib::Effect::SetDevice (graph->Device(), graph->Context());

	//�V�[���쐬
	m_scene = new PlayScene    ();
}

// �Q�[�����X�V���� Update game
void MyGame::Update(DX::StepTimer const& timer) {
	float elapsedTime = float(timer.GetElapsedSeconds());

	// TODO: �X�V������ǉ����� Add your update process here

	//�L�[�{�[�h�̍X�V����
	ShunLib::KeyManager::GetInstance()->Update();

	//�V�[���̍X�V
	m_scene->Update();

}

// �V�[����`�悷�� Draws the scene
void MyGame::Render(DX::StepTimer const& timer) {
	// �ŏ��̍X�V�̑O�͉����`�悵�Ȃ��悤�ɂ��� Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}

	// TODO: �����_�����O�R�[�h��ǉ����� Add your rendering code here
	// ��ʂ��N���A���� Clear Screen
	Clear();

	m_scene->Render();

	// �o�b�N�o�b�t�@���X�N���[���ɑ��� Presents the back buffer contents to the screen
	Present();
}

// �I�������������Ȃ� Finalize Game
void MyGame::Finalize() {
	// ��{�N���X��Finalize���Ăяo��
	Game::Finalize();

	DELETE_POINTER(m_scene);

	ShunLib::KeyManager::GetInstance()->Destroy();
}
