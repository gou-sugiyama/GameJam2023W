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
}

//---------------------------
// �X�V
//---------------------------
void Bomb::Update()
{
	if (padkey::OnClick(XINPUT_BUTTON_B))
	{
		FireOn = 1;
	}
}

//---------------------------
// �`��
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

// ����
void Bomb::Explosion()const
{
	DrawGraph(500, 300, ExplosionImg, TRUE);
}

//---------------------------
// ���e�̕`��
//---------------------------
void Bomb::DrawBomb()const
{
	DrawGraph(500, 300, BombImg, TRUE);
}
