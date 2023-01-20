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
	explosionTime = 0;
}

//---------------------------
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
	explosionTime = 0;
}

//---------------------------
// 更新
//---------------------------
void Bomb::Update()
{
	if (explosionTime <= 0)
	{
		explosionTime--;
	}
	else
	{
		key = D_EXPLOSION;
	}
}

//---------------------------
// 描画
//---------------------------
void Bomb::Draw()const
{
	if (!FireOn)
	{
		DrawBomb();
	}
	else
	{
		if (!(key == D_EXPLOSION))
		{		
			DrawExplosion();
		}
	}
}

// 爆発
void Bomb::Explosion()
{
	FireOn = 1;
	explosionTime = 40;
}

//---------------------------
// 爆弾の描画
//---------------------------
void Bomb::DrawBomb()const
{
	DrawRotaGraph(x, y, 1.0, 0, BombImg, TRUE);
}

void Bomb::DrawExplosion()const
{
	DrawRotaGraph(x, y, 1.0, 0, ExplosionImg, TRUE);
}