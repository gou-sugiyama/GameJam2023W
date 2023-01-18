#pragma once
#include <vector>
#include "common.h"
#include "Fire.h"
using namespace std;

//�摜�T�C�Y
#define D_FUSESIZE D_SCREEN_HEIGHT / 18		//720�̂Ƃ�40
#define D_BOMSIZE D_SCREEN_HEIGHT / 12		//720�̂Ƃ�60

//�`��ʒu�p--------------------------------------------------------------------------------------
#define D_FUSES_FIRST_X 280	//1280(��ʕ�) - 760(fuse�S�̕�) / 2(���T�C�h��) + 20(�s�{�b�g�ʒu)
#define D_FUSES_LAST_X 280 + 760 //first + fuse�S�̕�
#define D_FUSES_LAST_Y D_SCREEN_HEIGHT - D_FUSESIZE			//720�̂Ƃ�
#define D_FUSES_FIRST_Y D_FUSES_LAST_Y - 400	//fuse�̉��[�̍��W - fuse�S�̍���
#define D_FUSES_CENTER D_SCREEN_WIDTH / 2
//------------------------------------------------------------------------------------------------

//�z��̃X�e�[�^�X-------------
#define D_BURNED 0
#define D_ON_FUSE 1
#define D_BUREND_FUSE_LEFT 2
#define D_ON_FUSE_LEFT 3
#define D_BUREND_FUSE_RIGHT 4
#define D_ON_FUSE_RIGHT 5
#define D_FUSE_NONE -1
//-----------------------------

#define D_FUSE_NUM_MAX 10 //���ΐ��̍ő�{��
#define D_FUSE_NUM_MIN 3  //���ΐ��̍ŏ��{��
#define D_FUSE_LENGTH 10  //���ΐ��̒���

struct T_Pos
{
	float x;
	float y;
};

class Fuses
{
private:
	vector<Fire*> fire;
	int fuseImages[6];//TODO:burned�̉摜�ǉ����Ĕz��ɂ���
	int fuseNum;	//�{��
	int fusesArrayMax;
	int** fuses;
	int timeToSpreadOut;

public:
	//�R���X�g���N�^
	Fuses();
	//�f�X�g���N�^
	~Fuses() ;

	//�X�V
	void Update();
	//�`��
	void Draw() const;

	//���ΐ��̐���
	int** MakeFuses(int fuseNum);

	//���ΐ��̏�����
	void InitFuses(int**fuses);

	//���ΐ��̍폜
	void DeleteFuses();

	//����
	void Ignite(int index);

	//�`��ʒu�̍쐬
	T_Pos MakeDrawPos(int index);

	//���ΐ��̕`��
	void DrawFuses() const;


	//�Q�b�^�[�E�Z�b�^�[
	int GetFuseNum()
	{
		return fuseNum;
	}

};

