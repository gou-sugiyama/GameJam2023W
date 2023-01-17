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
{
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
	}


}

//---------------------------
// 
//---------------------------

//---------------------------
// 
//---------------------------