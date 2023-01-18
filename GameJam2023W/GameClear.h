#pragma once
#include "AbstractScene.h"
class GameClear :
	public AbstractScene
{
private:
	int count;
	int GHandle;

public:
	//コンストラクタ
	GameClear();

	//デストラクタ
	~GameClear() {}

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理

	void ten() const;
};

