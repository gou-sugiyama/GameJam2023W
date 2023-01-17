#include "DxLib.h"
#include "GameClear.h"
#include "Title.h"
#include "GameOver.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameClear::GameClear()
{
	/*old = now;
	now = PadInput();
	keyflg = now&~old;*/
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
}

//-------------------
// �`��
//-------------------
void GameClear::Draw() const
{
	SetFontSize(50);
	DrawString(500, 300, "Game Clear!", 0xffffff);
	DrawString(300, 660, "-- B�{�^���Ń^�C�g���ɖ߂� --", 0xffffff);
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameClear::ChangeScene()
{
	if (sceneFlg)
	{
		return new GameOver();
	}
	return this;
	
}