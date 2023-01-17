#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"
#include "result.h"


//-------------------
// コンストラクタ
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
	count = 0;
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


	if (count++<30)
	{
		ten();
	}
	else if(count++<60)
	{
		
	}
	else if(count==90)
	{
		count = 0;
	}
}

//-------------------
// 描画
//-------------------
void GameClear::Draw() const
{
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (sceneFlg)
	{
		return new result();
	}
	return this;
	
}

void GameClear::ten() const
{
	SetFontSize(32);
	DrawString(400, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
}