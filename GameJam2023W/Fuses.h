#pragma once
#include "common.h"

//画像サイズ
#define D_FUSESIZE D_SCREEN_HEIGHT / 18		//720のとき40
#define D_BOMSIZE D_SCREEN_HEIGHT / 12		//720のとき60

//描画位置用--------------------------------------------------------------------------------------
#define D_FUSES_FIRST_X 280	//1280(画面幅) - 760(fuse全体幅) / 2(両サイド幅) + 20(ピボット位置)
#define D_FUSES_LAST_X 280 + 760 //first + fuse全体幅
#define D_FUSES_LAST_Y D_SCREEN_HEIGHT - D_FUSESIZE			//720のとき
#define D_FUSES_FIRST_Y D_FUSES_LAST_Y - 400	//fuseの下端の座標 - fuse全体高さ
//------------------------------------------------------------------------------------------------

//配列のステータス-------------
#define D_BURNED 0
#define D_ON_FUSE 1
#define D_ON_CROSSED_FUSES 2
#define D_FUSE_NONE -1
//-----------------------------

#define D_FUSE_NUM_MAX 10 //導火線の最大本数
#define D_FUSE_NUM_MIN 3  //導火線の最小本数
#define D_FUSE_LENGTH 10  //導火線の長さ

class Fuses
{
private:
	int fuseImages;//TODO:burnedの画像追加して配列にする
	int fuseNum;	//本数
	int fusesArrayMax;
	int** fuses;

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
	void InitFuses();

	//導火線の削除
	void DeleteFuses();
};

