#include "result.h"
#include "DxLib.h"
#include "Title.h"

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
	if (count++<30)
	{
		ten();
	}
	else if (count<60) 
	{

	}
	else if(count<90)
	{
		count = 0;
	}
}


void result::Draw() const
{
	DrawFormatString(400, 450, cr, "倒した敵の数:%d", b);
	DrawFormatString(720, 450, cr, "スコア:%d", a);
}

AbstractScene* result::ChangeScene()
{
	if (sceneFlg)
	{
		return this;
	}
	return this;
}

void result::ten() const
{
	SetFontSize(32);
	DrawString(400, 660, "-- Bボタンでタイトルに戻る --", 0xffffff);
}