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
	fuseImages[D_BURNED]			= LoadGraph("images/burned_fuse.png");
	fuseImages[D_ON_FUSE]			= LoadGraph("images/fuse.png");
	fuseImages[D_BUREND_FUSE_LEFT]	 = LoadGraph("images/burned_fuse_left.png");
	fuseImages[D_ON_FUSE_LEFT]		 = LoadGraph("images/fuse_left.png");
	fuseImages[D_BUREND_FUSE_RIGHT] = LoadGraph("images/burned_fuse_right.png");
	fuseImages[D_ON_FUSE_RIGHT]		 = LoadGraph("images/fuse_right.png");
	fuseNum = 10;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
	timeToSpreadOut = 0;
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
	timeToSpreadOut++;

}

//---------------------------
// 描画
//---------------------------
void Fuses::Draw() const
{

	DrawFuses();

#define _DEBUG_
#ifdef _DEBUG_
	//for (int i = 0; i < fusesArrayMax; i++)
	//{
	//	for (int j = 0; j < D_FUSE_LENGTH; j++)
	//	{
	//		//if (i % 2 == 0)
	//		{
	//			DrawFormatString(D_FUSES_FIRST_X + 30 * i,
	//				D_FUSES_FIRST_Y + 30 * j, 0xffffff,
	//				"%d", fuses[i][j]);
	//		}
	//	}
	//}

	DrawPixel(D_SCREEN_WIDTH / 2, D_SCREEN_HEIGHT / 2, 0xff0000);
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
	
	InitFuses(fuses);


	return fuses;
}

//------------------------
// 導火線の初期化
//------------------------
void Fuses::InitFuses(int** fuses)
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

	//TODO:決め打ちなので後で消す---
	fuses[1][4] = D_ON_FUSE;
	fuses[0][4] = D_ON_FUSE_RIGHT;
	fuses[2][4] = D_ON_FUSE_LEFT;
	//------------------------------
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

//-------------------------------------------
// 着火　引数：左から何番目か (0始まり)
//-------------------------------------------
void Fuses::Ignite(int index)
{

}

//----------------------
// 導火線の描画
//----------------------
void Fuses::DrawFuses() const
{
	int center = D_SCREEN_WIDTH / 2;
	int sideShift = fusesArrayMax / 2;  //表示上の計算で、小数点以下切り捨て
	

	for (int i = 0; i < fusesArrayMax; i++)
	{
		for (int j = 0; j < D_FUSE_LENGTH; j++)
		{
	
			if (fuses[i][j] != D_FUSE_NONE) 
			{
				//縦の導火線
				if (i % 2 == 0)
				{
					DrawRotaGraph(center + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, 0, fuseImages[fuses[i][j]], TRUE);
				}
				else //横の導火線
				{
					DrawRotaGraph(center + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, M_PI / 180 * 90, fuseImages[fuses[i][j]], TRUE);
				}
			}

			
		}
	}
}