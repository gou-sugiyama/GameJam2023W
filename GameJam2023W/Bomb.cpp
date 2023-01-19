#include "DxLib.h"
#include "Bomb.h"
#include <math.h>
#include "Fuses.h"
#include "padkey.h"

//---------------------------
// コンストラクタ
//---------------------------
Bomb::Bomb()
{
	BombImg = LoadGraph("images/game jam/爆弾/bakudan2.PNG");
	ExplosionImg = LoadGraph("images/game jam/爆弾/爆発/bakuhatu3.png");
	FireOn = 0;
	fuseNum = 7;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
}

//---------------------------
// 更新
//---------------------------
void Bomb::Update()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		FireOn = 1;
	}
}

//---------------------------
// 描画
//---------------------------
void Bomb::Draw()const
{
	if (FireOn == 0)
	{
		DrawBomb();
	}
	else
	{
		Explosion();
	}
}

// 爆発
void Bomb::Explosion()const
{
	DrawGraph(500, 300, ExplosionImg, TRUE);
}

int** Bomb::MakeFuses(int fuseNum)
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

	return fuses;
}


//---------------------------
// 爆弾の描画
//---------------------------
void Bomb::DrawBomb()const
{
	int sideShift = fusesArrayMax / 2;  //表示上の計算で、小数点以下切り捨て
	int i = fusesArrayMax;
	int take = 0;
	int li = 0;

	if (take++ < 3) {
	   li = rand() % i;
	}


 	//縦の導火線
	if (li % 2 == 0)
	{
		DrawGraph(D_FUSES_CENTER + 40 * (li - sideShift) - 30,
			200, BombImg, TRUE);
	}
}