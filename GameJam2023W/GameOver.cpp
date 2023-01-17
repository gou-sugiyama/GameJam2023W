#include "GameOver.h"
#include "DxLib.h"
#include "Title.h"


//-------------------
// �R���X�g���N�^
//-------------------
GameOver::GameOver()
{
	cr = GetColor(255, 255, 255);
	a = 0;
	b = 0;
	/*old = now;
	now = PadInput();
	keyflg = now & ~old;*/
}

//-------------------
// �X�V
//-------------------
void GameOver::Update()
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
void GameOver::Draw() const
{
	SetFontSize(50);
	DrawString(510, 300, "Game Over", 0xffffff);
	SetFontSize(35);
	DrawFormatString(670, 450, cr, "�X�R�A:%d", a);
	DrawFormatString(380, 450, cr, "�|�����G�̐�:%d", b);
	DrawString(370, 660, "-- B�{�^���Ń^�C�g���ɖ߂� --", 0xffffff);
}

//-------------------
// �V�[���؂芷��
//-------------------
AbstractScene* GameOver::ChangeScene()
{
	if (sceneFlg)
	{
		return this;
	}
	return this;
}