#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"

//----------------------------
// コンストラクタ
//----------------------------
Title::Title()
{

}

//-------------------------
// 更新
//-------------------------
void Title::Update() 
{
	t++;
	if (t > 180)
	{
		sceneFlg = true;
	}
}

//-----------------------
// 描画
//-----------------------
void Title::Draw() const 
{
	DrawString(0, 20, "TitleScene", 0xffffff);
}

//-------------------------
// シーン切り換え
//-------------------------
AbstractScene* Title::ChangeScene()
{
	if (sceneFlg)
	{
		return new GameMain();
	}

	return this;
}