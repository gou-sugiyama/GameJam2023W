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
}//---------------------------
// コンストラクタ
//---------------------------
Bomb::Bomb(int x,int y,int key)
{
	this->x = x;
	this->y = y;
	this->key = key;
	BombImg = LoadGraph("images/game jam/爆弾/bakudan2.PNG");
	ExplosionImg = LoadGraph("images/game jam/爆弾/爆発/bakuhatu3.png");
	FireOn = 0;
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

//---------------------------
// 爆弾の描画
//---------------------------
void Bomb::DrawBomb()const
{
	DrawRotaGraph(x, y, 1.0, 0, BombImg, TRUE);
}