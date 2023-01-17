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

	DebagCount = 0;
}

//-------------------------
// 更新
//-------------------------
void Title::Update() 
{
	Pad();
	/*if (120 < DebagCount++) {
		sceneCHG = true;
	}*/
	if (FlgY == 0 && InputY < -MARGIN) {
		if (2 < ++SelectY) SelectY = 0;
	}
	if (FlgY == 0 && InputY > MARGIN) {
		if (--SelectY < 0) SelectY = 2;
	}

	if (padkey::OnClick(XINPUT_BUTTON_A)) {
		sceneCHG = true;
	}
}

//-----------------------
// 描画
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);

	int MenuY = 50 * SelectY;
	DrawTriangle(100, 50 + MenuY, 120, 55 + MenuY, 100, 60 + MenuY, 0xffffff, true);
}

//-------------------------
// シーン切り換え
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneCHG) {
		if (SelectY == 0) {
			return new GameMain;
		}
		if (SelectY == 1) {
			return new Help;
		}
		if (SelectY == 2) {
			return new GameEnd;
		}
	}

	return this;
}

void Title::Pad() {
	InputY = padkey::GetPadThumblY();
	if (OldY > MARGIN && InputY > MARGIN) {
		FlgY = 1;
	}
	else if (OldY < -MARGIN && InputY < -MARGIN)FlgY = 1;
	else { FlgY = 0; }
	OldY = InputY;
}