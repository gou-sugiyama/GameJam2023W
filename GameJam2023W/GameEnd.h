#pragma once
#include "AbstractScene.h"

class GameEnd : public AbstractScene
{
private:
	int SelectY;     //Y座標の決定値
	int MenuY;       //カーソルのY座標の移動値
	bool sceneCHG;   //シーン変更値

	int Count;

	int Endimg;
	int EndTitle;
	int Bomb;
	int Explosion;

public:
	static int END;         //終了

public:
	GameEnd();

	//デストラクタ
	~GameEnd() {};

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

	void End_Anim() const;
};

