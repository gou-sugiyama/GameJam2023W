#include "DxLib.h"
#include "Bomb.h"
#include <math.h>
#include "Fuses.h"
#include "padkey.h"

//---------------------------
// �R���X�g���N�^
//---------------------------
Bomb::Bomb()
{
	BombImg = LoadGraph("images/game jam/���e/bakudan2.PNG");
	ExplosionImg = LoadGraph("images/game jam/���e/����/bakuhatu3.png");
	FireOn = 0;
	explosionTime = 0;
}

//---------------------------
// �R���X�g���N�^
//---------------------------
Bomb::Bomb(int x,int y,int key)
{
	this->x = x;
	this->y = y;
	this->key = key;
	BombImg = LoadGraph("images/game jam/���e/bakudan2.PNG");
	ExplosionImg = LoadGraph("images/game jam/���e/����/bakuhatu3.png");
	FireOn = 0;
	explosionTime = 0;
}

//---------------------------
// �X�V
//---------------------------
void Bomb::Update()
{
	if (explosionTime > 0)
	{
		explosionTime--;
		if (explosionTime <= 0)
		{
			key = D_EXPLOSION;
		}

	}
}

//---------------------------
// �`��
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

// ����
void Bomb::Explosion()
{
	FireOn = 1;
	explosionTime = 40;
}

//---------------------------
// ���e�̕`��
//---------------------------
void Bomb::DrawBomb()const
{
	DrawRotaGraph(x, y, 1.0, 0, BombImg, TRUE);
}

void Bomb::DrawExplosion()const
{
	DrawRotaGraph(x, y, 1.0, 0, ExplosionImg, TRUE);
}