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
}

//-----------------------
// �`��
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);
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