#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"
#include "result.h"


//-------------------
// コンストラクタ
//-------------------
GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
	count = 0;
	/*old = now;
	now = PadInput();
	keyflg = now & ~old;*/
}

//-------------------
// 更新
//-------------------
void GameOver::Update()
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}

	if (count++ < 30) {
		ten();
	}
	else if (count++ < 60) {
		
	}
	else if (count == 90) {
		count = 0;
	}
}

//-------------------
// 描画
//-------------------
void GameOver::Draw() const
{
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xffffff);
	SetFontSize(35);
	
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameOver::ChangeScene()
{
	if (sceneFlg)
	{
		return new result();
	}
	return this;
}

void GameOver::ten() const
{
	SetFontSize(35);
	DrawString(370, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
}