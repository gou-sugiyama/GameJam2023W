#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"
#include "GameClear.h"
#include "GameOver.h"

//-------------------
// コンストラクタ
//-------------------
GameMain::GameMain()
{

}

//-------------------
// 更新
//-------------------
void GameMain::Update()
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}
}

//-------------------
// 描画
//-------------------
void GameMain::Draw() const
{
	DrawString(0, 20, "GameMainScene", 0xffffff);
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameMain::ChangeScene()
{
	/*if (DX_INPUT_PAD1)
	{
		return new GameOver();
	}*/

	if (sceneFlg)
	{
		return new GameClear();
	}
	return this;
}