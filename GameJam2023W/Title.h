#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int SelectY;     //Y座標の決定値
	int MenuY;       //カーソルのY座標の移動値
	bool sceneCHG;   //シーン変更値

	int DebagCount;
	//int GHandle;

public:
	Title();

	// デストラクタ
	~Title() {}

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

	void Pad();
};
