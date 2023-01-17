#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "Help.h"
#include "GameEnd.h"

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
}

//-----------------------
// 描画
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);
}

//-------------------------
// シーン切り換え
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneCHG) {
		return new Help;
	}

	return this;
}