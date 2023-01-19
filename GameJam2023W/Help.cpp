#include "DxLib.h"
#include "Help.h"
#include "Title.h"
#include "padkey.h"

Help::Help() {
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;

	Helpimg = LoadGraph("images/title/Helpimg.png");
	HelpBack = LoadGraph("images/title/HelpBack.png");

	DebagCount = 0;
}

void Help::Update() {
	if (padkey::OnClick(XINPUT_BUTTON_B)) {
		sceneCHG = true;
	}
}

void Help::Draw() const {
	static int count = 0;
	DrawGraph(0, 0, Helpimg, TRUE);
	if (count++ < 30) {
		DrawGraph(0, 0, HelpBack, TRUE);
	}
	else if (count++ < 60) {

	}
	else {
		count = 0;
	}
}

AbstractScene* Help::ChangeScene() {
	if (sceneCHG) {
		return new Title;
	}

	return this;
}