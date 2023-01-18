#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"
#include "result.h"
#include "padkey.h"


//-------------------
// コンストラクタ
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
	count = 0;
	GHandle = LoadGraph("images/game jam/背景/クリア クリアリザルト画面.png");
}

//-------------------
// 更新
//-------------------
void GameClear::Update()
{
	ten();
}

//-------------------
// 描画
//-------------------
void GameClear::Draw() const
{
	DrawGraph(0, 0, GHandle, TRUE);
	ten();
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new result;
	}
	return this;
	
}

void GameClear::ten() const
{
	static int count = 0;
	if (count++ < 70) {
		SetFontSize(35);
		DrawString(350, 660, "-- Bボタンを押してリザルトに進む --", 0xffffff);
	}
	if (count++ < 140) {

	}
	if (count == 210) {
		count = 0;
	}
	
}