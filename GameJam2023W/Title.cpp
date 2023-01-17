#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "Help.h"
#include "GameEnd.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
Title::Title()
{
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;

	DebagCount = 0;
}

//-------------------------
// �X�V
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
	*/

	MenuY = SelectY + 1;
}

//-----------------------
// �`��
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);

	DrawTriangle(100, 50 + MenuY, 120, 55 + MenuY, 100, 60 + MenuY, 0xffffff, true);
}

//-------------------------
// �V�[���؂芷��
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneCHG) {
		return new Help;
	}

	return this;
}