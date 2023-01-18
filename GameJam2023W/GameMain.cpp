#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"
#include "Enemy.h"

//-------------------
// コンストラクタ
//-------------------
GameMain::GameMain()
{

}

//-------------------
// 更新
//-------------------
void GameMain::Update()
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}
}

//-------------------
// 描画
//-------------------
void GameMain::Draw() const
{
	DrawString(0, 20, "GamaMainScene", 0xffffff);
	
	LoadEnemyImages();
	DrawEnemy();
	EnemyDamage();
}

//-------------------
// シーン切り換え
//-------------------
AbstractScene* GameMain::ChangeScene()
{
	if (sceneFlg)
	{
		return new Title();
	}
	return this;
}