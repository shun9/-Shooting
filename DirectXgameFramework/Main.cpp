// DirectX Game Framework 0.94 
// 2017/05/05　Added Japanese comment
// 2017/05/08  Added Graphics singleton class
// 2017/05/13  Added Window class
// 2017/05/20  Functioning WinMain function
// 2017/05/25  Change global Game object to local Game object
// 2017/05/29  Create Window object inside Game object
// 2017/07/01  Add MyGame class derrived from Game class

#include "Window.h"
#include "MyGame.h"

using namespace DirectX;

// エントリポイント Entry point
int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    if (!XMVerifyCPUSupport())
        return 1;
	// COMライブラリを初期化する
    if (FAILED(CoInitializeEx(nullptr, COINITBASE_MULTITHREADED)))
        return 1;

	int width = 800;
	int height = 600;
	// Gameオブジェクトを生成する
	MyGame game(width, height);
	// ゲームを実行する
	MSG msg = game.Run();

	// COMライブラリの終了処理する
    CoUninitialize();
    return (int) msg.wParam;
}
