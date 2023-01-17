#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Fuses.h"
#include "common.h"


//---------------------------
// コンストラクタ
//---------------------------
Fuses::Fuses()
{
	fuseImages = LoadGraph("images/fusetest.png");
	fuseNum = 10;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
}

//---------------------------
// デストラクタ
//---------------------------
Fuses::~Fuses()
{
	DeleteFuses();
}

//---------------------------
// 更新
//---------------------------
void Fuses::Update()
{

}

//---------------------------
// 描画
//---------------------------
void Fuses::Draw() const
{/*
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 == 0)
			{
				DrawRotaGraph(D_FUSES_FIRST_X + 40 * i, 
					D_FUSES_FIRST_Y + 40 * j, 
					1.0,0,fuseImages, TRUE);
				
			}
			if (i == 1 && j == 5)
			{
				DrawRotaGraph(D_FUSES_FIRST_X + 40 * i,
					D_FUSES_FIRST_Y + 40 * j,
					1.0, M_PI/180*90, fuseImages, TRUE);
			}
		}
	}*/

#define _DEBUG_
#ifdef _DEBUG_
	for (int i = 0; i < fusesArrayMax; i++)
	{
		for (int j = 0; j < D_FUSE_LENGTH; j++)
		{
			//if (i % 2 == 0)
			{
				DrawFormatString(D_FUSES_FIRST_X + 30 * i,
					D_FUSES_FIRST_Y + 30 * j, 0xffffff,
					"%d", fuses[i][j]);
			}
		}
	}
#endif
}

//---------------------------
// 導火線の生成
//---------------------------
int** Fuses::MakeFuses(int fuseNum)
{
	int** fuses;
	//引数チェック
	if (fuseNum > D_FUSE_NUM_MAX)
	{
		return nullptr;
	}

	//外部から作成されている場合の処理
	if (fuseNum != this->fuseNum)
	{
		this->fuseNum = fuseNum;
	}

	fusesArrayMax = fuseNum * 2 - 1; //一本につき1間隔、端はいらないので-1

	//fusesの動的確保
	fuses = new int* [fusesArrayMax];
	for (int i = 0; i < fusesArrayMax; i++)
	{
		fuses[i] = new int[D_FUSE_LENGTH];
	}
	
	InitFuses();


	return fuses;
}

//------------------------
// 導火線の初期化
//------------------------
void Fuses::InitFuses()
{
	//fusesへ値を代入する
	for (int i = 0; i < fusesArrayMax; i++)
	{
		for (int j = 0; j < D_FUSE_LENGTH; j++)
		{
			if (i % 2 == 0)
			{
				fuses[i][j] = D_ON_FUSE;
			}
			else
			{
				fuses[i][j] = D_FUSE_NONE;
			}

		}
	}
}

//---------------------------
// 導火線の削除
//---------------------------
void Fuses::DeleteFuses()
{
	for (int i = 0; i < fusesArrayMax; i++)
	{
		delete[] fuses[i];
	}
	delete[] fuses;
}