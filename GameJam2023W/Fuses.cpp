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
	fuseImages[D_BURNED_FUSE_LEFT]	 = LoadGraph("images/burned_fuse_left.png");
	fuseImages[D_ON_FUSE_LEFT]		 = LoadGraph("images/fuse_left.png");
	fuseImages[D_BURNED_FUSE_RIGHT] = LoadGraph("images/burned_fuse_right.png");
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

	vector<Fire*>::iterator it = fire.begin();
	for (; it != fire.end(); it++)
	{
		delete* it;
	}
}

//---------------------------
// 更新
//---------------------------
void Fuses::Update()
{
	vector<Fire*>::iterator it = fire.begin();
	for (; it != fire.end(); it++)
	{
		(*it)->Update();
	}

	timeToSpreadOut++;
	if (timeToSpreadOut % 30 == 0)
	{

		//実行フラグの初期化
		for (auto it = current.begin(); it != current.end(); it++)
		{
			(*it).exeFlg = true;
		}

		NewFire();
		SpreadFlames();
	}
	Extinguishing();
}

//---------------------------
// 描画
//---------------------------
void Fuses::Draw() const
{

	DrawFuses();

	
	for (auto it = fire.begin(); it != fire.end(); it++)
	{
		(*it)->Draw();
	}

//#define _DEBUG_
#ifdef _DEBUG_
	//for (int i = 0; i < fusesArrayMax; i++)
	//{
	//	for (int j = 0; j < D_FUSE_LENGTH; j++)
	//	{
	//		//if (i % 2 == 0)
	//		{
	//			DrawFormatString(D_FUSES_FIRST_X + 40 * i,
	//				D_FUSES_FIRST_Y + 40 * j, 0xFFFF00,
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

	DecorateFuses(fuses);

	return fuses;
}

//----------------------------------------
// 飾り付け
//----------------------------------------
void Fuses::DecorateFuses(int** fuses)
{
	int none = fuseNum - 4;
	int lowFuseNum = fuseNum - 3;
	
	for (int i = 0; i < lowFuseNum; i++)
	{
		int x;
		int y;
		do
		{
			x = GetRand(fuseNum - 2) * 2 + 1;
			y = GetRand(D_FUSE_LENGTH - 3) + 1;//１～８までにおさえたい
		} 
		while (fuses[x][y - 1] == D_ON_FUSE
			|| fuses[x][y + 1] == D_ON_FUSE
			|| fuses[x + 1][y] == D_ON_FUSE_RIGHT
			|| fuses[x - 1][y] == D_ON_FUSE_LEFT);
	

		fuses[x][y] = D_ON_FUSE;
		fuses[x - 1][y] = D_ON_FUSE_RIGHT;
		fuses[x + 1][y] = D_ON_FUSE_LEFT;
	}

	for (int i = 0; i < none; i++)
	{
		int x = GetRand(fuseNum - 1) * 2;
		int y = GetRand(D_FUSE_LENGTH - 3) + 1;//１～８までにおさえたい

		fuses[x][y] = D_FUSE_NONE;
	}

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

//define _SEED_
#ifdef _SEED_
	//TODO:決め打ちなので後で消す---
	fuses[0][4] = D_ON_FUSE_RIGHT;
	fuses[1][4] = D_ON_FUSE;
	fuses[2][4] = D_ON_FUSE_LEFT;
	fuses[2][1] = D_ON_FUSE_RIGHT;
	fuses[3][1] = D_ON_FUSE;
	fuses[4][1] = D_ON_FUSE_LEFT;
	fuses[4][7] = D_ON_FUSE_RIGHT;
	fuses[5][7] = D_ON_FUSE;
	fuses[6][7] = D_ON_FUSE_LEFT;
	fuses[8][7] = D_ON_FUSE_RIGHT;
	fuses[9][7] = D_ON_FUSE;
	fuses[10][7] = D_ON_FUSE_LEFT;
	fuses[10][1] = D_ON_FUSE_RIGHT;
	fuses[11][1] = D_ON_FUSE;
	fuses[12][1] = D_ON_FUSE_LEFT;
		
	
	//------------------------------
#endif
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
void Fuses::Ignite(int fuseNum)
{
	int index = fuseNum * 2; //本数を受け取って、配列の添え字に直す
	T_Pos pos = MakePos(index, D_FUSE_LENGTH - 1);

	//火を作る
	fire.push_back(new Fire(pos, D_DIRECTION_UP));
	current.push_back(T_FusesIndex(index, D_FUSE_LENGTH - 2));

	auto it = --current.end();
	//Fireがどこまですすめるか測る
	int count = 0;
	for (int i = 0;
		(*it).y - i >= 0 
		&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
		&& fuses[(*it).x][(*it).y - i] % 2 != 0;
		i++)
	{
		count++;
	}
	(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する
	

	fuses[index][D_FUSE_LENGTH - 1] -= 1;
}

//-----------------------------------------------------
// 火の生成 引数：fusesの中のどこを燃やすか
//-----------------------------------------------------
void Fuses::NewFire()
{
	bool down = false;
	T_FusesIndex tmp;
	//交差点を踏んだら増殖する
	for (auto it = current.begin(); it != current.end(); it++)
	{
		int test = fuses[(*it).x][(*it).y];
		if (fuses[(*it).x][(*it).y] == D_ON_FUSE_RIGHT
			&& (*it).exeFlg == true)
		{
			(*it).exeFlg = false;
			//ポジション作ってFireを作る
			if (fuses[(*it).x + 1][(*it).y] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_RIGHT));
				//Fireがどこまですすめるか測る
				int count = 0;
				for (int i = 0;
					(*it).x + i < fusesArrayMax
					&& fuses[(*it).x + i][(*it).y] != D_FUSE_NONE
					&& fuses[(*it).x + i][(*it).y] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する
				fuses[(*it).x][(*it).y] -= 1;
				current.push_back(T_FusesIndex((*it).x + 1, (*it).y));
				(--current.end())->exeFlg = false;
			}
			else if (fuses[(*it).x][(*it).y - 1] != D_BURNED
				&& fuses[(*it).x][(*it).y + 1] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_UP));
				//Fireがどこまですすめるか測る
				int count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y - i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する

				fire.push_back(new Fire(pos, D_DIRECTION_DOWN));
				//Fireがどこまですすめるか測る
				count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y + i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y + i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する
		

				fuses[(*it).x][(*it).y] -= 1;
				tmp = *it;
				current.push_back(T_FusesIndex((*it).x, (*it).y - 1));
				(--current.end())->exeFlg = false;
				down = true;
			}
			else
			{
				fuses[(*it).x][(*it).y] -= 1;
			}
			if (down == true)
			{
				current.push_back(T_FusesIndex(tmp.x, tmp.y + 1));
				(--current.end())->exeFlg = false;
			}
			NewFire();
			break;
		}
		else if (fuses[(*it).x][(*it).y] == D_ON_FUSE_LEFT
			&& (*it).exeFlg == true)
		{
			(*it).exeFlg = false;
			//ポジション作ってFireを作る
			if (fuses[(*it).x - 1][(*it).y] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_LEFT));
				//Fireがどこまで進めるかはかる
				int count = 0;
				for (int i = 0;
					(*it).x - i >= 0
					&& fuses[(*it).x - i][(*it).y] != D_FUSE_NONE
					&& fuses[(*it).x - i][(*it).y] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する
				fuses[(*it).x][(*it).y] -= 1;
				current.push_back(T_FusesIndex((*it).x - 1, (*it).y));
				(--current.end())->exeFlg = false;
			}
			else if (fuses[(*it).x][(*it).y - 1] != D_BURNED
				&& fuses[(*it).x][(*it).y + 1] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_UP));
				//Fireがどこまですすめるか測る
				int count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y - i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する

				fire.push_back(new Fire(pos, D_DIRECTION_DOWN));
				//Fireがどこまですすめるか測る
				count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y + i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y + i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する


				fuses[(*it).x][(*it).y] -= 1;
				tmp = *it;
				current.push_back(T_FusesIndex((*it).x, (*it).y - 1));
				(--current.end())->exeFlg = false;
				
				down = true;
			}
			else
			{
				fuses[(*it).x][(*it).y] -= 1;
			}
			if (down == true)
			{
				current.push_back(T_FusesIndex(tmp.x, tmp.y + 1));
				(--current.end())->exeFlg = false;
			}
			NewFire();
			break;
		}
		else if (fuses[(*it).x][(*it).y] == D_ON_FUSE)
		{
			fuses[(*it).x][(*it).y] -= 1;
		}
	}



}

//-----------------------------------
// 描画位置の作成（火花用）
//-----------------------------------
T_Pos Fuses::MakePos(int fusesX,int fusesY)
{
	T_Pos pos;
	int sideShift = fusesArrayMax / 2;
	pos.x = (float)(D_FUSES_CENTER + D_FUSESIZE * (fusesX - sideShift));
	pos.y = (float)(D_FUSES_FIRST_Y + D_FUSESIZE * fusesY);

	return pos;
}

//------------------------------------
// 役目を終えた火を鎮火する
//------------------------------------
void Fuses::Extinguishing()
{
	for (auto it = fire.begin(); it != fire.end(); it++)
	{
		if ((*it)->GetDeleteFlg() == true)
		{
			delete* it;
			fire.erase(it);
			Extinguishing();
			break;
		}
	}
}

//------------------------------
// 延焼
//------------------------------
void Fuses::SpreadFlames()
{


	for (auto it = current.begin(); it != current.end(); it++)
	{


		//T_Pos pos = MakePos((*it).x, (*it).y);
		//fire.push_back(new Fire(pos, D_DIRECTION_RIGHT));
		//int count = 0;
		//for (int i = 0;
		//	(*it).x + i < fusesArrayMax
		//	&& fuses[(*it).x + i + 1][(*it).y] != D_FUSE_NONE;
		//	i++)
		//{
		//	count++;
		//}
		//(*--fire.end())->SetFrame(count * 30);	//vec.end()には何も入ってないから-1する
		//right = true;
		////current.push_back(T_FusesIndex((*it).x, (*it).y));



		//上・下・左・右を確認して燃え広がる
		if ((*it).y - 1 >= 0
			&& fuses[(*it).x][(*it).y - 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_RIGHT
			)
		{
			(*it).y -= 1;
			continue;
		}

		if ((*it).y + 1 < D_FUSE_LENGTH
			&& fuses[(*it).x][(*it).y + 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_RIGHT
			)
		{
			(*it).y += 1;
			continue;
		}


		if (((*it).x) - 1 >= 0)
		{

			if (
				fuses[(*it).x - 1][(*it).y] == D_ON_FUSE
				|| fuses[(*it).x - 1][(*it).y] == D_ON_FUSE_LEFT
				|| fuses[(*it).x - 1][(*it).y] == D_ON_FUSE_RIGHT
				)
			{
				(*it).x -= 1;
				continue;
			}


		}

		if ((*it).x + 1 < fusesArrayMax
			&& fuses[(*it).x + 1][(*it).y] == D_ON_FUSE
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_LEFT
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_RIGHT
			)
		{
			(*it).x += 1;
			continue;
		}


	}
}

//----------------------
// 導火線の描画
//----------------------
void Fuses::DrawFuses() const
{
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
					DrawRotaGraph(D_FUSES_CENTER + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, 0, fuseImages[fuses[i][j]], TRUE);
				}
				else //横の導火線
				{
					DrawRotaGraph(D_FUSES_CENTER + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, M_PI / 180 * 90, fuseImages[fuses[i][j]], TRUE);
				}
			}
#ifdef _DEBUG_

			DrawFormatString(D_FUSES_CENTER + 40 * (i - sideShift),
				D_FUSES_FIRST_Y + 40 * j,
				0xFFFF00, "%d", fuses[i][j]);
#endif
			
		}
	}
}