#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "Help.h"
#include "GameEnd.h"
#include "GameOver.h"
#include "GameClear.h"
#include "padkey.h"

//----------------------------
// コンストラクタ
//----------------------------
Title::Title()
{
	SelectY = 0;
	sceneCHG = false;
	OldY = 0;
	InputY = 0;
	FlgY = 0;
	SceneCHGCount = 0;
	SceneCHGFlg = false;
	KeyFlg = true;

	Titleimg = LoadGraph("images/title/title.png");
	TitleNameimg = LoadGraph("images/title/title_name.png");
	Startimg = LoadGraph("images/title/start.png");
	Helpimg = LoadGraph("images/title/help.png");
	Endimg = LoadGraph("images/title/end.png");
	Carsorimg = LoadGraph("images/title/ka-soru.png");
}

//-------------------------
// 更新
//-------------------------
void Title::Update() 
{
	Pad();

	if (KeyFlg) {
		if (padkey::OnClick(XINPUT_BUTTON_DPAD_DOWN)) {
			if (2 < ++SelectY) SelectY = 0;
		}
		if (padkey::OnClick(XINPUT_BUTTON_DPAD_UP)) {
			if (--SelectY < 0) SelectY = 2;
		}

		if (padkey::OnClick(XINPUT_BUTTON_B)) {
			SceneCHGFlg = true;
			KeyFlg = false;
		}
	}

	if (SceneCHGFlg) {
		if (120 < SceneCHGCount++) {
			sceneCHG = true;
		}
	}
}

//-----------------------
// 描画
//-----------------------
void Title::Draw() const 
{
	DrawGraph(0, 0, Titleimg, TRUE);
	DrawGraph(0, 0, TitleNameimg, TRUE);

	Flashing();

	int MenuY = 130 * SelectY;
	int MenuX = -20 * SelectY;
	/*DrawTriangle(100, 50 + MenuY, 120, 55 + MenuY, 100, 60 + MenuY, 0xffffff, true);*/
	DrawGraph(0 + MenuX, 0 + MenuY, Carsorimg, TRUE);
}

void Title::Flashing() const {
	static bool ViewStart = true;
	static bool ViewHelp = true;
	static bool ViewEnd = true;
	static bool ViewFlash = false;

	static bool OnceFlg = true;

	static int count = 0;
	static int take = 0;

	if (padkey::OnClick(XINPUT_BUTTON_B)) {
		if (SelectY == 0) {
			ViewStart = false;
			ViewFlash = true;
		}
		if (SelectY == 1) {
			ViewHelp = false;
			ViewFlash = true;
		}
		if (SelectY == 2) {
			ViewEnd = false;
			ViewFlash = true;
		}
	}

	if (ViewFlash) {
		if (SelectY == 0) {
			if (count++ < 10) {
				DrawGraph(0, 0, Startimg, TRUE);
			}
			else if (count++ < 20) {

			}
			else {
				count = 0;
				++take;
			}
			if (4 < take) {
				ViewStart = true;
				ViewFlash = false;
				take = 0;
				count = 0;
			}
		}
		if (SelectY == 1) {
			if (count++ < 10) {
				DrawGraph(0, 0, Helpimg, TRUE);
			}
			else if (count++ < 20) {

			}
			else {
				count = 0;
				++take;
			}
			if (4 < take) {
				ViewHelp = true;
				ViewFlash = false;
				take = 0;
				count = 0;
			}
		}
		if (SelectY == 2) {
			if (count++ < 10) {
				DrawGraph(0, -5, Endimg, TRUE);
			}
			else if (count++ < 20) {

			}
			else {
				count = 0;
				++take;
			}
			if (4 < take) {
				ViewEnd = true;
				ViewFlash = false;
				take = 0;
				count = 0;
			}
		}
	}

	if (ViewStart) {
		DrawGraph(0, 0, Startimg, TRUE);
	}
	if (ViewHelp) {
		DrawGraph(0, 0, Helpimg, TRUE);
	}
	if (ViewEnd) {
		DrawGraph(0, -5, Endimg, TRUE);
	}
}

//-------------------------
// シーン切り換え
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneCHG) {
		if (SelectY == 0) {
			KeyFlg = true;
			return new GameMain;
		}
		if (SelectY == 1) {
			KeyFlg = true;
			return new Help;
		}
		if (SelectY == 2) {
			KeyFlg = true;
			return new GameEnd;
		}
	}

	return this;
}

void Title::Pad() {
	if (SceneCHGFlg) {
		InputY = 0;
	}
	else {
		InputY = padkey::GetPadThumblY();
		if (OldY > MARGIN && InputY > MARGIN) {
			FlgY = 1;
		}
		else if (OldY < -MARGIN && InputY < -MARGIN)FlgY = 1;
		else { FlgY = 0; }
		OldY = InputY;
	}
}