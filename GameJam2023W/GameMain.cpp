#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"
#include "GameClear.h"
#include "GameOver.h"
#include "padkey.h"
#include "common.h"
#include "Fuses.h"

int	gFire = 0;
int gFireX;				// �J�[�\����X���W
int gFuse = 0;

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
	gFuse = fuses->GetFuseNum() - 1;
	if (padkey::OnClick(XINPUT_BUTTON_Y))
	{
		sceneFlg = true;
	}
	if (padkey::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (++gFire > gFuse) gFire = 0;
	}
	if (padkey::OnClick(XINPUT_BUTTON_DPAD_LEFT))
	{
		if (--gFire < 0) gFire = gFuse;
	}
	gFireX = 255 + (40 * (2 % gFuse)) + gFire * 80;
}

//-------------------
// �`��
//-------------------
void GameMain::Draw() const
{
	fuses->Draw();
	DrawString(0, 20, "GamaMainScene", 0xffffff);
	DrawBox(0, 410, 200, 720, 0xffffff, TRUE);
	DrawBox(1080, 410, 1280, 720, 0xffffff, TRUE);
	DrawString(0, 20, "GameMainScene", 0xffffff);

	DrawBox(gFireX, 630, gFireX + 50, 680, 0xff0000, FALSE);

	DrawFormatString(0, 100, 0xffffff, "%d", fuses->GetFuseNum());	//TODO: ������
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameMain::ChangeScene()
{
	/*if (DX_INPUT_PAD1)
	{
		return new GameOver();
	}*/

	if (sceneFlg)
	{
		return new GameClear();
	}
	return this;
}