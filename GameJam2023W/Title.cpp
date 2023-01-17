#include "DxLib.h"
#include "Title.h"
#include "GameMain.h"
#include "GameOver.h"
#include "GameClear.h"
#include "padkey.h"

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
	if (padkey::OnClick(XINPUT_BUTTON_B))
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
		return new GameMain();
	}

	return this;
}