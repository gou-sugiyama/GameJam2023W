#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"
#include "result.h"
#include "padkey.h"
#include "over_result.h"


//-------------------
// �R���X�g���N�^
//-------------------

GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
}

//-------------------
// �X�V
//-------------------
void GameOver::Update()
{
	ten();
}

//-------------------
// �`��
//-------------------
void GameOver::Draw() const
{
	ten();
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xfffff0);
}

void GameOver::ten() const
{
	static int count = 0;
	if (count++ < 70) {
		SetFontSize(35);
		DrawString(330, 660, "-- B�{�^���������ă��U���g�ɐi�� --", 0xfffff0);
	}
	if (count++ < 140) {

	}
	if (count == 210) {
		count = 0;
	}
	
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameOver::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new over_result;
	}
	return this;
}

