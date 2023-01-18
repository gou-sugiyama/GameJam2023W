#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"
#include "result.h"
#include "padkey.h"


//-------------------
// コンストラクタ
//-------------------

GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
	GHandle = LoadGraph("images/game jam/背景/草むら.jpg");
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
	ten();
}

//-------------------
// 描画
//-------------------
void GameOver::Draw() const
{
	DrawGraph(0, 0, GHandle, TRUE);
	ten();
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xffffff);
}

void GameOver::ten() const
{
	static int count = 0;
	if (count++ < 70) {
		SetFontSize(35);
		DrawString(370, 660, "-- Bボタンを押してリザルトに進む --", 0xffffff);
	}
	if (count++ < 140) {

	}
	if (count == 210) {
		count = 0;
	}
	
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameOver::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new result();
	}
	return this;
}

