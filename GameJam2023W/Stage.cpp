#include "Stage.h"

Stage::Stage() {
	Stageimg = LoadGraph("images/game jam/�w�i/green.png");
}

void Stage::DrawStage() const {
	DrawGraph(0, 0, Stageimg, FALSE);
}