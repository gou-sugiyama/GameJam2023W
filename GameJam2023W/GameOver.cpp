#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"


//-------------------
// コンストラクタ
//-------------------
GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
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
}

//-------------------
// 描画
//-------------------
void GameOver::Draw() const
{
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xffffff);
	SetFontSize(35);
	DrawFormatString(670, 450, cr, "スコア:%d", a);
	DrawFormatString(380, 450, cr, "倒した敵の数:%d", b);
	DrawString(370, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameOver::ChangeScene()
{
	if (sceneFlg)
	{
		return this;
	}
	return this;
}