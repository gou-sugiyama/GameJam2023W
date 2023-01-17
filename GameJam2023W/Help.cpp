#include "DxLib.h"
#include "Help.h"
#include "Title.h"
#include "padkey.h"

Help::Help() {
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;

	DebagCount = 0;
}

void Help::Update() {
	if (padkey::OnClick(XINPUT_BUTTON_A)) {
		sceneCHG = true;
	}
}

void Help::Draw() const {
	DrawString(0, 20, "HelpScene", 0xffffff);
}

AbstractScene* Help::ChangeScene() {
	if (sceneCHG) {
		return new Title;
	}

	return this;
}