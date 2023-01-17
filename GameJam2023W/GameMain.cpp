#include "DxLib.h"
#include "GameMain.h"
#include "Title.h"


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