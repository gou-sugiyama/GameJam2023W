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
	fuseNum = 8;
	fusesArrayMax = 0;
	fuses = MakeFuses(fuseNum);
	timeToSpreadOut = 0;


	Ignite(0);
}

//---------------------------
// �f�X�g���N�^
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
// �X�V
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
		SpreadFlames();
	}
	Extinguishing();
}

//---------------------------
// �`��
//---------------------------
void Fuses::Draw() const
{

	DrawFuses();

	
	for (auto it = fire.begin(); it != fire.end(); it++)
	{
		(*it)->Draw();
	}

#define _DEBUG_
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
void Fuses::Ignite(int fuseNum)
{
	int index = fuseNum * 2; //�{�����󂯎���āA�z��̓Y�����ɒ���
	T_Pos pos = MakePos(index, D_FUSE_LENGTH - 1);

	//�΂����
	fire.push_back(new Fire(pos, D_DIRECTION_UP));
	(*--fire.end())->SetFrame((D_FUSE_LENGTH - 1) * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
	current.push_back(T_FusesIndex(index, D_FUSE_LENGTH - 1));

	fuses[index][D_FUSE_LENGTH - 1] -= 1;
}

//-----------------------------------------------------
// �΂̐��� �����Ffuses�̒��̂ǂ���R�₷��
//-----------------------------------------------------
void Fuses::NewFire(T_FusesIndex tFuses)
{

}

//-----------------------------------
// �`��ʒu�̍쐬�i�Ήԗp�j
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
// ��ڂ��I�����΂���΂���
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
// ����
//------------------------------
void Fuses::SpreadFlames()
{
	for (auto it = current.begin(); it != current.end(); it++)
	{
		bool up = false;
		bool right = false;
		bool down = false;
		bool left = false;

		if ((*it).x + 1 < fusesArrayMax
			&& fuses[(*it).x + 1][(*it).y] == D_ON_FUSE
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_LEFT
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_RIGHT
			)
		{
			T_Pos pos = MakePos((*it).x + 1, (*it).y);
			fire.push_back(new Fire(pos, D_DIRECTION_RIGHT));
			int count = 0;
			for (int i = 0;
				(*it).x + i < fusesArrayMax
				&& fuses[(*it).x + i + 1][(*it).y] != D_FUSE_NONE;
				i++)
			{
				count++;
			}
			(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
			right = true;
			//current.push_back(T_FusesIndex((*it).x, (*it).y));


		}

		//��E���E���E�E���m�F���ĔR���L����
		if ((*it).y - 1 >= 0
			&& fuses[(*it).x][(*it).y - 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_RIGHT
			)
		{
			fuses[(*it).x][(*it).y - 1] -= 1;
			(*it).y -= 1;
		}

		if ((*it).y + 1 < D_FUSE_LENGTH
			&& fuses[(*it).x][(*it).y + 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_RIGHT
			)
		{
			fuses[(*it).x][(*it).y + 1] -= 1;
			(*it).y += 1;
		}
	}
}

//----------------------
// ���ΐ��̕`��
//----------------------
void Fuses::DrawFuses() const
{
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
					DrawRotaGraph(D_FUSES_CENTER + 40 * (i - sideShift),
						D_FUSES_FIRST_Y + 40 * j,
						1.0, 0, fuseImages[fuses[i][j]], TRUE);
				}
				else //���̓��ΐ�
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