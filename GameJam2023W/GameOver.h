#pragma once
#include "AbstractScene.h"
class GameOver :
	public AbstractScene
{
private:
	int cr;
	int a;
	int b;
	int GHandle;

public:
	//コンストラクタ
	GameOver();

	//デストラクタ
	~GameOver() {}

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

	void ten() const;
};

