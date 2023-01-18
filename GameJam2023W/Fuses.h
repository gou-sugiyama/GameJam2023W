#pragma once
#include <vector>
#include <stack>
#include "common.h"
#include "T_Pos.h"
#include "Fire.h"
using namespace std;

//画像サイズ
#define D_FUSESIZE D_SCREEN_HEIGHT / 18		//720のとき40
#define D_BOMSIZE D_SCREEN_HEIGHT / 12		//720のとき60

//描画位置用--------------------------------------------------------------------------------------
#define D_FUSES_FIRST_X 280	//1280(画面幅) - 760(fuse全体幅) / 2(両サイド幅) + 20(ピボット位置)
#define D_FUSES_LAST_X 280 + 760 //first + fuse全体幅
#define D_FUSES_LAST_Y D_SCREEN_HEIGHT - D_FUSESIZE			//720のとき
#define D_FUSES_FIRST_Y D_FUSES_LAST_Y - 400	//fuseの下端の座標 - fuse全体高さ
#define D_FUSES_CENTER D_SCREEN_WIDTH / 2
//------------------------------------------------------------------------------------------------

//配列のステータス-------------
#define D_BURNED 0
#define D_ON_FUSE 1
#define D_BUREND_FUSE_LEFT 2
#define D_ON_FUSE_LEFT 3
#define D_BUREND_FUSE_RIGHT 4
#define D_ON_FUSE_RIGHT 5
#define D_FUSE_NONE -1
//-----------------------------

#define D_FUSE_NUM_MAX 10 //導火線の最大本数
#define D_FUSE_NUM_MIN 3  //導火線の最小本数
#define D_FUSE_LENGTH 10  //導火線の長さ

struct T_FusesIndex
{
	int x;
	int y;

	T_FusesIndex(int x, int y)
	{
		this->x = x;
		this->y = y;
	}

};

class Fuses
{
private:
	vector<Fire*> fire;
	vector<T_FusesIndex> current;
	int fuseImages[6];
	int fuseNum;	//本数
	int fusesArrayMax;
	int** fuses;
	int timeToSpreadOut;
public:
	//コンストラクタ
	Fuses();
	//デストラクタ
	~Fuses() ;

	//更新
	void Update();
	//描画
	void Draw() const;

	//導火線の生成
	int** MakeFuses(int fuseNum);

	//導火線の初期化
	void InitFuses(int**fuses);

	//導火線の削除
	void DeleteFuses();

	//着火
	void Ignite(int fuseNum);

	//火の生成
	void NewFire(T_Pos pos);

	//描画位置の作成
	T_Pos MakePos(int fusesX,int fusesY);

	//役目を終えた火を鎮火する
	void Extinguishing();

	//火の延焼
	void SpreadFlames();

	//導火線の描画
	void DrawFuses() const;


	//ゲッター・セッター
	int GetFuseNum()
	{
		return fuseNum;
	}

};

