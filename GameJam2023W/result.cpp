#include "result.h"
#include "DxLib.h"
#include "Title.h"
#include "padkey.h"

result::result() 
{
	a = 0;
	b = 0;
	cr = GetColor(255, 255, 255);
	sceneFlg = false;
	count = 0;
}

void result::Update()
{
	ten();
}


void result::Draw() const
{
	DrawGraph(0, 0, GHandle, TRUE);
	ten();
	DrawFormatString(400, 450, cr, "倒した敵の数:%d", b);
	DrawFormatString(720, 450, cr, "スコア:%d", a);
}

AbstractScene* result::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new Title;
	}
	return this;
}

void result::ten() const
{
	static int count;
	if (count++ < 70)
	{
		SetFontSize(32);
		DrawString(400, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
	}
	else if (count < 140)
	{

	}
	else if (count < 210)
	{
		count = 0;
	}
	
}