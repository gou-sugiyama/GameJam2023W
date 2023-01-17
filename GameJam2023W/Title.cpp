#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "GameOver.h"

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
	/*if(DX_INPUT_PAD1)
	{
		return new GameMain();
	}*/
	if (sceneFlg)
	{
		return new GameOver();
	}

	return this;
}