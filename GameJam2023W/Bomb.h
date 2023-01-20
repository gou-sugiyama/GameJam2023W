#pragma once
#include "Fuses.h"

#define Bomb_Rand GetRand(10)

class Bomb
{
private:
	int key;
	int x;
	int y;
	int BombImg;
	int ExplosionImg;
	int BombNum;
	int** bombs;
	int FireOn;

public:
	//�R���X�g���N�^�@���ꂽ�Ƃ��ɌĂ΂��
	Bomb();
	Bomb(int x,int y,int key);
	//�f�X�g���N�^�@�������Ƃ��ɌĂ΂��
	~Bomb() {};

	//�X�V �Q�[�����C���Ŗ��t���[����������
	void Update();
	//�`�� �`�悷����̂͑S������
	void Draw()const;

	// ���e�̐���
	int** MakeBomb(int BombNum);
	
	// ���e�̏�����
	void InitBomb(int** Bombs);
	
	// ���e�̍폜
	void DeleteBomb();
	
	// ����
	void Explosion()const;

	//���e�̕`��
	void DrawBomb()const;


	int GetKey() { return key; }
};

