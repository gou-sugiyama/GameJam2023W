#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"

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
	if (t > 180)
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