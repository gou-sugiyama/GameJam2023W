#include "DxLib.h"
#include "GameEnd.h"
#include "Title.h"
#include "Help.h"

int GameEnd::END;

GameEnd::GameEnd() {
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;
	END = 0;

	DebagCount = 0;
}

void GameEnd::Update() {
	if (120 < DebagCount++) {
		//sceneCHG = true;
		END = 99;
	}
}

void GameEnd::Draw() const {
	DrawString(0, 20, "GameEndScene", 0xffffff);
}

AbstractScene* GameEnd::ChangeScene() {

	return this;
}