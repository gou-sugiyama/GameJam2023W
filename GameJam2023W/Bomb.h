#pragma once
#include "Fuses.h"

#define D_EXPLOSION 999

class Bomb
{
private:
	int key;
	int x;
	int y;
	int BombImg;
	int ExplosionImg;
	int BombNum;
	int** bombs;
	int FireOn;
	int explosionTime;

public:
	//コンストラクタ　作られたときに呼ばれる
	Bomb();
	Bomb(int x,int y,int key);
	//デストラクタ　消されるときに呼ばれる
	~Bomb() {};

	//更新 ゲームメインで毎フレーム処理する
	void Update();
	//描画 描画するものは全部ここ
	void Draw()const;
	
	// 爆発
	void Explosion();

	//爆弾の描画
	void DrawBomb()const;
	//爆発の描画
	void DrawExplosion()const;


	int GetKey() { return key; }
};

