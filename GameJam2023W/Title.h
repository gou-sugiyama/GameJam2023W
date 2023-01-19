#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int SelectY;     //Y座標の決定値
	bool sceneCHG;   //シーン変更値
	int OldY;
	int InputY;
	int FlgY;
	int SceneCHGCount;
	bool SceneCHGFlg;
	bool KeyFlg;

	int Titleimg;     //タイトルイメージ
	int TitleNameimg; //タイトルネームイメージ
	int Startimg;     //スタートイメージ
	int Helpimg;      //ヘルプイメージ
	int Endimg;       //エンドイメージ
	int Carsorimg;    //カーソルイメージ

public:
	Title();

	// デストラクタ
	~Title() {}

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

	void Flashing() const;  //画像の点滅処理
	void Pad();
};
