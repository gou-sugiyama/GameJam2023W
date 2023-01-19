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
	GHandle = LoadGraph("images/game jam/背景/クリア クリアリザルト画面.png");
}

void result::Update()
{
	if (padkey::OnClick(XINPUT_BUTTON_A))
	{
		sceneFlg = true;
	}
	ten();
}


void result::Draw() const
{
	DrawGraph(0, 0, GHandle, TRUE);
	ten();
	SetFontSize(35);
	DrawFormatString(400, 350, cr, "倒した敵の数:%d", b);
	DrawFormatString(720, 350, cr, "スコア:%d", a);
}

AbstractScene* result::ChangeScene()
{
	if (sceneFlg)
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
		DrawString(380, 660, "-- Aボタンでタイトルに戻る --", 0xffffff);
	}
	else if (count < 140)
	{

	}
	else if (count < 210)
	{
		count = 0;
	}
}