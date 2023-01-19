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
	fuseNum = 7;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
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

int** Bomb::MakeFuses(int fuseNum)
{
	int** fuses;
	//�����`�F�b�N
	if (fuseNum > D_FUSE_NUM_MAX)
	{
		return nullptr;
	}

	//�O������쐬����Ă���ꍇ�̏���
	if (fuseNum != this->fuseNum)
	{
		this->fuseNum = fuseNum;
	}

	fusesArrayMax = fuseNum * 2 - 1; //��{�ɂ�1�Ԋu�A�[�͂���Ȃ��̂�-1

	//fuses�̓��I�m��
	fuses = new int* [fusesArrayMax];

	return fuses;
}


//---------------------------
// ���e�̕`��
//---------------------------
void Bomb::DrawBomb()const
{
	int sideShift = fusesArrayMax / 2;  //�\����̌v�Z�ŁA�����_�ȉ��؂�̂�
	int i = fusesArrayMax;
	int take = 0;
	int li = 0;

	if (take++ < 3) {
	   li = rand() % i;
	}


 	//�c�̓��ΐ�
	if (li % 2 == 0)
	{
		DrawGraph(D_FUSES_CENTER + 40 * (li - sideShift) - 30,
			200, BombImg, TRUE);
	}
}