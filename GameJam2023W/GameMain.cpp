#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameMain::GameMain()
{

}

//-------------------
// �X�V
//-------------------
void GameMain::Update()
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}
}

//-------------------
// �`��
//-------------------
void GameMain::Draw() const
{
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