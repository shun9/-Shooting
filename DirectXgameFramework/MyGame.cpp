#include "MyGame.h"

/*--[ShunLib]--*/
#include <SL_MacroConstants.h>
#include <SL_Model.h>
#include <SL_Texture.h>
#include <SL_KeyManager.h>

#include "Classes\Scene\PlayScene.h"
#include "Classes\Scene\SceneMachine.h"
#include "Classes\Other\ScoreCounter.h"

using namespace Microsoft;
using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

// コンストラクタ Constructor
MyGame::MyGame(int width, int height) : Game(width, height){
}

// MyGameオブジェクトを初期する Initialize MyGame object
void MyGame::Initialize() {
	// 基本クラスのInitializeを呼び出す
	Game::Initialize();

	//デバイス設定
	Graphics* graph = &(Graphics::Get());
	ShunLib::Model::SetDevice  (graph->Device(), graph->Context());
	ShunLib::Texture::SetDevice(graph->Device(), graph->Context());

	SceneMachine::GetInstance()->ChangeScene(new PlayScene);
}

// ゲームを更新する Update game
void MyGame::Update(DX::StepTimer const& timer) {
	float elapsedTime = float(timer.GetElapsedSeconds());

	// TODO: 更新処理を追加する Add your update process here

	//キーボードの更新処理
	ShunLib::KeyManager::GetInstance()->Update();

	SceneMachine::GetInstance()->Update();
}

// シーンを描画する Draws the scene
void MyGame::Render(DX::StepTimer const& timer) {
	// 最初の更新の前は何も描画しないようにする Don't try to render anything before the first Update.
	if (timer.GetFrameCount() == 0) {
		return;
	}

	// TODO: レンダリングコードを追加する Add your rendering code here
	// 画面をクリアする Clear Screen
	Clear();

	SceneMachine::GetInstance()->Render();

	// バックバッファをスクリーンに送る Presents the back buffer contents to the screen
	Present();
}

// 終了処理をおこなう Finalize Game
void MyGame::Finalize() {
	// 基本クラスのFinalizeを呼び出す
	Game::Finalize();

	ShunLib::KeyManager::GetInstance()->Destroy();
	SceneMachine::Destroy();
	ScoreCounter::Destroy();
}
