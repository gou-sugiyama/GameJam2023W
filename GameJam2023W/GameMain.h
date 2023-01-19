#pragma once
#include "AbstractScene.h"
#include "Fuses.h"
#include "Bomb.h"
class GameMain :
    public AbstractScene
{
private:
	Fuses* fuses;
	Bomb* bombs;
	int t = 0; //TODO:消してね
	bool sceneFlg = false; //TODO:消してね

public:
	//コンストラクタ
	GameMain();

	//デストラクタ
	~GameMain();

	void Update() override;						//描画以外の更新処理
	void Draw() const override;					//描画の更新処理
	AbstractScene* ChangeScene() override;		//シーンの変更処理
};

