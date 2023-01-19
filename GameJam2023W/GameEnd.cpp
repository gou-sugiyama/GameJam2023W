#include "DxLib.h"
#include "GameEnd.h"
#include "Title.h"

int GameEnd::END;

GameEnd::GameEnd() {
	SelectY = 0;
	MenuY = 0;
	sceneCHG = false;
	END = 0;

	Endimg = LoadGraph("images/title/endimg.png");
	EndTitle = LoadGraph("images/title/end_title.png");
	Bomb = LoadGraph("images/game jam/”š’e/bakudan.png");
	Explosion = LoadGraph("images/game jam/”š’e/”š”­/bakuhatu2.png");

	Count = 0;
}

void GameEnd::Update() {
	if (400 < Count++) {
		END = 99;
	}
}

void GameEnd::Draw() const {
	DrawGraph(0, 0, Endimg, TRUE);
	DrawGraph(0, 0, EndTitle, TRUE);

	End_Anim();
}

AbstractScene* GameEnd::ChangeScene() {

	return this;
}

void GameEnd::End_Anim() const {
	static int count = 0;
	static int BombCount = 0;
	static int StartCount = 0;
	static int ExplosionCount = 0;

	static float BombX = 1280.0;
	static float BombY = 0.0;
	static float MoveX = 0.0;
	static float MoveY = 0.0;

	if (120 < count++) {
		if (440 < BombX && BombY < 360) {
			MoveX = -20.0;
			++BombCount;
			BombX += MoveX;
			BombY += MoveY;
			DrawGraph(BombX, BombY, Bomb, TRUE);
			if (BombCount / 10) {
				MoveY += 0.5;
			}
		}
		else {
			if (StartCount++ < 120) {
				DrawGraph(BombX, BombY, Bomb, TRUE);
			}
			else {
				ExplosionCount += 10;
				DrawExtendGraph(350 - ExplosionCount, 230 - ExplosionCount,
					850 + ExplosionCount, 800 + ExplosionCount, Explosion, TRUE);
			}
		}
	}
}