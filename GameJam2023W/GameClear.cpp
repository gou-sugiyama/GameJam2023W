#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"
#include "result.h"
#include "padkey.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
	count = 0;
	GHandle = LoadGraph("images/game jam/�w�i/�N���A �N���A���U���g���.png");
}

//-------------------
// �X�V
//-------------------
void GameClear::Update()
{
	ten();
}

//-------------------
// �`��
//-------------------
void GameClear::Draw() const
{
	DrawGraph(0, 0, GHandle, TRUE);
	ten();
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new result;
	}
	return this;
	
}

void GameClear::ten() const
{
	static int count = 0;
	if (count++ < 70) {
		SetFontSize(35);
		DrawString(350, 660, "-- B�{�^���������ă��U���g�ɐi�� --", 0xffffff);
	}
	if (count++ < 140) {

	}
	if (count == 210) {
		count = 0;
	}
	
}