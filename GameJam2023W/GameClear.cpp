#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"


//-------------------
// コンストラクタ
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
}

//-------------------
// 更新
//-------------------
void GameClear::Update()
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
void GameClear::Draw() const
{
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
	DrawString(300, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (sceneFlg)
	{
		return new GameOver();
	}
	return this;
	
}