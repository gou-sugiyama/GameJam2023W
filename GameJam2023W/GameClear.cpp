#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"
#include "result.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
	count = 0;
}

//-------------------
// �X�V
//-------------------
void GameClear::Update()
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}


	if (count++<30)
	{
		ten();
	}
	else if(count++<60)
	{
		
	}
	else if(count==90)
	{
		count = 0;
	}
}

//-------------------
// �`��
//-------------------
void GameClear::Draw() const
{
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (sceneFlg)
	{
		return new result();
	}
	return this;
	
}

void GameClear::ten() const
{
	SetFontSize(32);
	DrawString(400, 660, "-- B�{�^���Ń^�C�g���ɖ߂� --", 0xffffff);
}