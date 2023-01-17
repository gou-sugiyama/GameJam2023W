#include "DxLib.h"
#include "GameEnd.h"
#include "Title.h"
#include "Help.h"

GameEnd::GameEnd() {
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;

	DebagCount = 0;
}

void GameEnd::Update() {
	if (120 < DebagCount++) {
		sceneCHG = true;
	}
}

void GameEnd::Draw() const {
	DrawString(0, 20, "GameEndScene", 0xffffff);
}

AbstractScene* GameEnd::ChangeScene() {
	if (sceneCHG) {
		return new Title;
	}

	return this;
}