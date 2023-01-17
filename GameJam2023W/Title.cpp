#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "padkey.h"

//----------------------------
// �R���X�g���N�^
//----------------------------
Title::Title()
{

}

//-------------------------
// �X�V
//-------------------------
void Title::Update() 
{
	t++;
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		sceneFlg = true;
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
	if (sceneFlg)
	{
		return new GameMain();
	}

	return this;
}