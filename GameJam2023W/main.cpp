#include "DxLib.h"
#include "common.h"
#include "SceneManager.h"
#include "GameEnd.h"
#include "padkey.h"
#include "FrameRateControll.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// タイトルを test に変更
	SetMainWindowText("GameJam2023Winter");

	ChangeWindowMode(TRUE);		// ウィンドウモードで起動

	SetGraphMode(D_SCREEN_WIDTH, D_SCREEN_HEIGHT, 32);

	if (DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

	SetMouseDispFlag(TRUE);	//マウスカーソル非表示

	SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

	SetFontSize(20);		// 文字サイズを設定

	//シーンマネージャーの確保
	SceneManager* sceneManager = new SceneManager();

	//フレームレートコントローラの確保
	FrameRateControll* frame = new FrameRateControll();

	// ゲームループ
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESCキー*/ &&
		GameEnd::END != 99
		)
	{
		padkey::UpdataKey();
		ClearDrawScreen();

		frame->Update();
		sceneManager->Update();
		sceneManager->Draw();

		frame->Wait();
		/*DrawString(0, 0, "FirstCommit", 0xFFFFFF);*/

		ScreenFlip();			// 裏画面の内容を表画面に反映
	}

	//シーンマネージャーの解放
	delete sceneManager;

	DxLib_End();	// DXライブラリ使用の終了処理

	return 0;	// ソフトの終了
}
