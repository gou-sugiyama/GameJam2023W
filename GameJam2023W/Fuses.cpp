#include "DxLib.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "Fuses.h"
#include "common.h"


//---------------------------
// �R���X�g���N�^
//---------------------------
Fuses::Fuses()
{
	fuseImages = LoadGraph("images/fusetest.png");
	fuseNum = 10;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
}

//---------------------------
// �f�X�g���N�^
//---------------------------
Fuses::~Fuses()
{
	DeleteFuses();
}

//---------------------------
// �X�V
//---------------------------
void Fuses::Update()
{

}

//---------------------------
// �`��
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
// ���ΐ��̐���
//---------------------------
int** Fuses::MakeFuses(int fuseNum)
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
	for (int i = 0; i < fusesArrayMax; i++)
	{
		fuses[i] = new int[D_FUSE_LENGTH];
	}
	
	InitFuses();


	return fuses;
}

//------------------------
// ���ΐ��̏�����
//------------------------
void Fuses::InitFuses()
{
	//fuses�֒l��������
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
// ���ΐ��̍폜
//---------------------------
void Fuses::DeleteFuses()
{
	for (int i = 0; i < fusesArrayMax; i++)
	{
		delete[] fuses[i];
	}
	delete[] fuses;
}