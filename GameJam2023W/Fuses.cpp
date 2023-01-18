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
	timeToSpreadOut++;

}

//---------------------------
// �`��
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
	
	InitFuses(fuses);


	return fuses;
}

//------------------------
// ���ΐ��̏�����
//------------------------
void Fuses::InitFuses(int** fuses)
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

	//TODO:���ߑł��Ȃ̂Ō�ŏ���---
	fuses[1][4] = D_ON_FUSE;
	fuses[0][4] = D_ON_FUSE_RIGHT;
	fuses[2][4] = D_ON_FUSE_LEFT;
	//------------------------------
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

//-------------------------------------------
// ���΁@�����F�����牽�Ԗڂ� (0�n�܂�)
//-------------------------------------------
void Fuses::Ignite(int index)
{

}

//----------------------
// ���ΐ��̕`��
//----------------------
void Fuses::DrawFuses() const
{
	int center = D_SCREEN_WIDTH / 2;
	int sideShift = fusesArrayMax / 2;  //�\����̌v�Z�ŁA�����_�ȉ��؂�̂�
	

	for (int i = 0; i < fusesArrayMax; i++)
	{
		for (int j = 0; j < D_FUSE_LENGTH; j++)
		{
	
			if (fuses[i][j] != D_FUSE_NONE) 
			{
				//�c�̓��ΐ�
				if (i % 2 == 0)
				{
					DrawRotaGraph(center + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, 0, fuseImages[fuses[i][j]], TRUE);
				}
				else //���̓��ΐ�
				{
					DrawRotaGraph(center + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, M_PI / 180 * 90, fuseImages[fuses[i][j]], TRUE);
				}
			}

			
		}
	}
}