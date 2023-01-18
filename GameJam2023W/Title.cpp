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
	MenuY = 0;
	sceneCHG = false;

	DebagCount = 0;
}

//-------------------------
// 更新
//-------------------------
void Title::Update() 
{
	if (120 < DebagCount++) {
		sceneCHG = true;
	}
	/*
	if () {
		if (2 < ++SelectY) SelectY = 0;
	}
	if () {
		if (++SelectY < 0) SelectY = 2;
	}
	if(){
		sceneCHG = true;
	}
	*/

	MenuY = SelectY + 1;
}

//-----------------------
// 描画
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);

	DrawTriangle(100, 50 + MenuY, 120, 55 + MenuY, 100, 60 + MenuY, 0xffffff, true);
}

//-------------------------
// シーン切り換え
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneCHG) {
		/*if (SelectY == 0) {
			return new GameMain;
		}
		if (SelectY == 1) {
			return new Help;
		}
		if (SelectY == 2) {
			return new GameEnd;
		}*/
		return new GameMain();
	}

	return this;
}

void Title::Pad() {

}