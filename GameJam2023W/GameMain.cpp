#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameMain::GameMain()
{
	fuses = new Fuses();
}

//-------------------
// �f�X�g���N�^
//-------------------
GameMain::~GameMain()
{
	delete fuses;
}

//-------------------
// �X�V
//-------------------
void GameMain::Update()
{
	fuses->Update();
	t++;
	if (t > 180)
	{
		//sceneFlg = true;  //TODO:�V�[���؂�ւ���~��
	}
}

//-------------------
// �`��
//-------------------
void GameMain::Draw() const
{
	fuses->Draw();
	DrawString(0, 20, "GamaMainScene", 0xffffff);
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameMain::ChangeScene()
{
	if (sceneFlg)
	{
		return new Title();
	}
	return this;
}