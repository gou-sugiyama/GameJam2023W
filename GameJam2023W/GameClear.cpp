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
	GHandle = LoadGraph("images/game jam/�w�i/��i�@���ނ�.jpg");
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
	static int count;
	if (count++ < 70)
	{
		SetFontSize(32);
		DrawString(400, 660, "-- B�{�^���Ń^�C�g���ɖ߂� --", 0xffffff);
	}
	else if (count++ < 140)
	{

	}
	else if (count == 210)
	{
		count = 0;
	}
	
}