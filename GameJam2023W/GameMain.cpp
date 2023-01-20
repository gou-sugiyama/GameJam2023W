#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"
#include "GameClear.h"
#include "GameOver.h"
#include "padkey.h"
#include "common.h"
#include "Enemy.h"

int	gFire = 0;
int gFireX;				// カーソルのX座標
int gFuse = 0;

//-------------------
// コンストラクタ
//-------------------
GameMain::GameMain()
{
	fuses = new Fuses();
	InitEnemy();
	bombs = new Bomb;
	LoadEnemyImages();
	stage = new Stage();
}

//-------------------
// デストラクタ
//-------------------
GameMain::~GameMain()
{
	delete fuses;
	delete bombs;
	delete stage;
}

//-------------------
// 更新
//-------------------
void GameMain::Update()
{
	fuses->Update();
	bombs->Update();
	gFuse = fuses->GetFuseNum() - 1;
	if (padkey::OnClick(XINPUT_BUTTON_Y))
	{
		sceneFlg = true;
	}
	if (padkey::OnClick(XINPUT_BUTTON_DPAD_RIGHT))
	{
		if (++gFire > gFuse) gFire = 0;
	}
	if (padkey::OnClick(XINPUT_BUTTON_DPAD_LEFT))
	{
		if (--gFire < 0) gFire = gFuse;
	}
	gFireX = 255 + (40 * ((gFuse + 1) % 2)) + (80 * ((10 - (gFuse + 1)) / 2)) + gFire * 80;

	if (padkey::OnClick(XINPUT_BUTTON_A))
	{
		fuses->Ignite(gFire);
	}
}

//-------------------
// 描画
//-------------------
void GameMain::Draw() const
{
	stage->DrawStage();
	fuses->Draw();
	//bombs->Draw();
	DrawBox(0, 410, 200, 720, 0xffffff, TRUE);
	DrawBox(1080, 410, 1280, 720, 0xffffff, TRUE);

	DrawBox(gFireX, 630, gFireX + 50, 680, 0xff0000, FALSE);

	
	DrawEnemy();
	EnemyDamage();
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameMain::ChangeScene()
{
	/*if (DX_INPUT_PAD1)
	{
		return new GameOver();
	}*/

	if (sceneFlg)
	{
		return new GameClear();
	}
	return this;
}