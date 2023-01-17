#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"


//-------------------
// コンストラクタ
//-------------------
GameMain::GameMain()
{
	fuses = new Fuses();
}

//-------------------
// デストラクタ
//-------------------
GameMain::~GameMain()
{
	delete fuses;
}

//-------------------
// 更新
//-------------------
void GameMain::Update()
{
	fuses->Update();
	t++;
	if (t > 180)
	{
		//sceneFlg = true;  //TODO:シーン切り替え停止中
	}
}

//-------------------
// 描画
//-------------------
void GameMain::Draw() const
{
	fuses->Draw();
	DrawString(0, 20, "GamaMainScene", 0xffffff);
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