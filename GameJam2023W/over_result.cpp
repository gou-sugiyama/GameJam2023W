#include "over_result.h"
#include "Title.h"
#include "padkey.h"

over_result::over_result()
{
	a = 0;
	b = 0;
	cr = GetColor(255, 255, 255);
	sceneFlg = false;
	count = 0;
}

void over_result::Update()
{
	ten();
}


void over_result::Draw() const
{
	ten();
	DrawFormatString(400, 350, cr, "�|�����G�̐�:%d", b);
	DrawFormatString(720, 350, cr, "�X�R�A:%d", a);
}

AbstractScene* over_result::ChangeScene()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		return new Title;
	}
	return this;
}

void over_result::ten() const
{
	static int count;
	if (count++ < 70)
	{
		SetFontSize(32);
		DrawString(380, 660, "-- B�{�^���Ń^�C�g���ɖ߂� --", 0xffffff);
	}
	else if (count < 140)
	{

	}
	else if (count < 210)
	{
		count = 0;
	}

}