#pragma once
#include "Fuses.h"

#define Bomb_Rand GetRand(10)

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

	// 爆弾の生成
	int** MakeBomb(int BombNum);
	
	// 爆弾の初期化
	void InitBomb(int** Bombs);
	
	// 爆弾の削除
	void DeleteBomb();
	
	// 爆発
	void Explosion()const;

	//爆弾の描画
	void DrawBomb()const;


	int GetKey() { return key; }
};

