#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"
#include "result.h"
#include "padkey.h"
#include "over_result.h"


//-------------------
// コンストラクタ
//-------------------

GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
}

//-------------------
// 更新
//-------------------
void GameOver::Update()
{
	ten();
}

//-------------------
// 描画
//-------------------
void GameOver::Draw() const
{
	ten();
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xfffff0);
}

void GameOver::ten() const
{
	static int count = 0;
	if (count++ < 70) {
		SetFontSize(35);
		DrawString(330, 660, "-- Bボタンを押してリザルトに進む --", 0xfffff0);
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
		return new over_result;
	}
	return this;
}

