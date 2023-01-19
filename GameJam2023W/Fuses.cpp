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
	fuseImages[D_BURNED_FUSE_LEFT]	 = LoadGraph("images/burned_fuse_left.png");
	fuseImages[D_ON_FUSE_LEFT]		 = LoadGraph("images/fuse_left.png");
	fuseImages[D_BURNED_FUSE_RIGHT] = LoadGraph("images/burned_fuse_right.png");
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

		//���s�t���O�̏�����
		for (auto it = current.begin(); it != current.end(); it++)
		{
			(*it).exeFlg = true;
		}

		NewFire();
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

//#define _DEBUG_
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

	DecorateFuses(fuses);

	return fuses;
}

//----------------------------------------
// ����t��
//----------------------------------------
void Fuses::DecorateFuses(int** fuses)
{
	int none = fuseNum - 4;
	int lowFuseNum = fuseNum - 3;
	
	for (int i = 0; i < lowFuseNum; i++)
	{
		int x;
		int y;
		do
		{
			x = GetRand(fuseNum - 2) * 2 + 1;
			y = GetRand(D_FUSE_LENGTH - 3) + 1;//�P�`�W�܂łɂ���������
		} 
		while (fuses[x][y - 1] == D_ON_FUSE
			|| fuses[x][y + 1] == D_ON_FUSE
			|| fuses[x + 1][y] == D_ON_FUSE_RIGHT
			|| fuses[x - 1][y] == D_ON_FUSE_LEFT);
	

		fuses[x][y] = D_ON_FUSE;
		fuses[x - 1][y] = D_ON_FUSE_RIGHT;
		fuses[x + 1][y] = D_ON_FUSE_LEFT;
	}

	for (int i = 0; i < none; i++)
	{
		int x = GetRand(fuseNum - 1) * 2;
		int y = GetRand(D_FUSE_LENGTH - 3) + 1;//�P�`�W�܂łɂ���������

		fuses[x][y] = D_FUSE_NONE;
	}

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

//define _SEED_
#ifdef _SEED_
	//TODO:���ߑł��Ȃ̂Ō�ŏ���---
	fuses[0][4] = D_ON_FUSE_RIGHT;
	fuses[1][4] = D_ON_FUSE;
	fuses[2][4] = D_ON_FUSE_LEFT;
	fuses[2][1] = D_ON_FUSE_RIGHT;
	fuses[3][1] = D_ON_FUSE;
	fuses[4][1] = D_ON_FUSE_LEFT;
	fuses[4][7] = D_ON_FUSE_RIGHT;
	fuses[5][7] = D_ON_FUSE;
	fuses[6][7] = D_ON_FUSE_LEFT;
	fuses[8][7] = D_ON_FUSE_RIGHT;
	fuses[9][7] = D_ON_FUSE;
	fuses[10][7] = D_ON_FUSE_LEFT;
	fuses[10][1] = D_ON_FUSE_RIGHT;
	fuses[11][1] = D_ON_FUSE;
	fuses[12][1] = D_ON_FUSE_LEFT;
		
	
	//------------------------------
#endif
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
	current.push_back(T_FusesIndex(index, D_FUSE_LENGTH - 2));

	auto it = --current.end();
	//Fire���ǂ��܂ł����߂邩����
	int count = 0;
	for (int i = 0;
		(*it).y - i >= 0 
		&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
		&& fuses[(*it).x][(*it).y - i] % 2 != 0;
		i++)
	{
		count++;
	}
	(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
	

	fuses[index][D_FUSE_LENGTH - 1] -= 1;
}

//-----------------------------------------------------
// �΂̐��� �����Ffuses�̒��̂ǂ���R�₷��
//-----------------------------------------------------
void Fuses::NewFire()
{
	bool down = false;
	T_FusesIndex tmp;
	//�����_�𓥂񂾂瑝�B����
	for (auto it = current.begin(); it != current.end(); it++)
	{
		int test = fuses[(*it).x][(*it).y];
		if (fuses[(*it).x][(*it).y] == D_ON_FUSE_RIGHT
			&& (*it).exeFlg == true)
		{
			(*it).exeFlg = false;
			//�|�W�V���������Fire�����
			if (fuses[(*it).x + 1][(*it).y] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_RIGHT));
				//Fire���ǂ��܂ł����߂邩����
				int count = 0;
				for (int i = 0;
					(*it).x + i < fusesArrayMax
					&& fuses[(*it).x + i][(*it).y] != D_FUSE_NONE
					&& fuses[(*it).x + i][(*it).y] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
				fuses[(*it).x][(*it).y] -= 1;
				current.push_back(T_FusesIndex((*it).x + 1, (*it).y));
				(--current.end())->exeFlg = false;
			}
			else if (fuses[(*it).x][(*it).y - 1] != D_BURNED
				&& fuses[(*it).x][(*it).y + 1] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_UP));
				//Fire���ǂ��܂ł����߂邩����
				int count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y - i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����

				fire.push_back(new Fire(pos, D_DIRECTION_DOWN));
				//Fire���ǂ��܂ł����߂邩����
				count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y + i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y + i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
		

				fuses[(*it).x][(*it).y] -= 1;
				tmp = *it;
				current.push_back(T_FusesIndex((*it).x, (*it).y - 1));
				(--current.end())->exeFlg = false;
				down = true;
			}
			else
			{
				fuses[(*it).x][(*it).y] -= 1;
			}
			if (down == true)
			{
				current.push_back(T_FusesIndex(tmp.x, tmp.y + 1));
				(--current.end())->exeFlg = false;
			}
			NewFire();
			break;
		}
		else if (fuses[(*it).x][(*it).y] == D_ON_FUSE_LEFT
			&& (*it).exeFlg == true)
		{
			(*it).exeFlg = false;
			//�|�W�V���������Fire�����
			if (fuses[(*it).x - 1][(*it).y] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_LEFT));
				//Fire���ǂ��܂Ői�߂邩�͂���
				int count = 0;
				for (int i = 0;
					(*it).x - i >= 0
					&& fuses[(*it).x - i][(*it).y] != D_FUSE_NONE
					&& fuses[(*it).x - i][(*it).y] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
				fuses[(*it).x][(*it).y] -= 1;
				current.push_back(T_FusesIndex((*it).x - 1, (*it).y));
				(--current.end())->exeFlg = false;
			}
			else if (fuses[(*it).x][(*it).y - 1] != D_BURNED
				&& fuses[(*it).x][(*it).y + 1] != D_BURNED)
			{
				T_Pos pos = MakePos((*it).x, (*it).y);
				fire.push_back(new Fire(pos, D_DIRECTION_UP));
				//Fire���ǂ��܂ł����߂邩����
				int count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y - i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y - i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����

				fire.push_back(new Fire(pos, D_DIRECTION_DOWN));
				//Fire���ǂ��܂ł����߂邩����
				count = 0;
				for (int i = 0;
					(*it).y - i >= 0
					&& fuses[(*it).x][(*it).y + i] != D_FUSE_NONE
					&& fuses[(*it).x][(*it).y + i] % 2 != 0;
					i++)
				{
					count++;
				}
				(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����


				fuses[(*it).x][(*it).y] -= 1;
				tmp = *it;
				current.push_back(T_FusesIndex((*it).x, (*it).y - 1));
				(--current.end())->exeFlg = false;
				
				down = true;
			}
			else
			{
				fuses[(*it).x][(*it).y] -= 1;
			}
			if (down == true)
			{
				current.push_back(T_FusesIndex(tmp.x, tmp.y + 1));
				(--current.end())->exeFlg = false;
			}
			NewFire();
			break;
		}
		else if (fuses[(*it).x][(*it).y] == D_ON_FUSE)
		{
			fuses[(*it).x][(*it).y] -= 1;
		}
	}



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


		//T_Pos pos = MakePos((*it).x, (*it).y);
		//fire.push_back(new Fire(pos, D_DIRECTION_RIGHT));
		//int count = 0;
		//for (int i = 0;
		//	(*it).x + i < fusesArrayMax
		//	&& fuses[(*it).x + i + 1][(*it).y] != D_FUSE_NONE;
		//	i++)
		//{
		//	count++;
		//}
		//(*--fire.end())->SetFrame(count * 30);	//vec.end()�ɂ͉��������ĂȂ�����-1����
		//right = true;
		////current.push_back(T_FusesIndex((*it).x, (*it).y));



		//��E���E���E�E���m�F���ĔR���L����
		if ((*it).y - 1 >= 0
			&& fuses[(*it).x][(*it).y - 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y - 1] == D_ON_FUSE_RIGHT
			)
		{
			(*it).y -= 1;
			continue;
		}

		if ((*it).y + 1 < D_FUSE_LENGTH
			&& fuses[(*it).x][(*it).y + 1] == D_ON_FUSE
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_LEFT
			|| fuses[(*it).x][(*it).y + 1] == D_ON_FUSE_RIGHT
			)
		{
			(*it).y += 1;
			continue;
		}


		if (((*it).x) - 1 >= 0)
		{

			if (
				fuses[(*it).x - 1][(*it).y] == D_ON_FUSE
				|| fuses[(*it).x - 1][(*it).y] == D_ON_FUSE_LEFT
				|| fuses[(*it).x - 1][(*it).y] == D_ON_FUSE_RIGHT
				)
			{
				(*it).x -= 1;
				continue;
			}


		}

		if ((*it).x + 1 < fusesArrayMax
			&& fuses[(*it).x + 1][(*it).y] == D_ON_FUSE
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_LEFT
			|| fuses[(*it).x + 1][(*it).y] == D_ON_FUSE_RIGHT
			)
		{
			(*it).x += 1;
			continue;
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