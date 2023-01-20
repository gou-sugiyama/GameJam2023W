#pragma once
#include "Fuses.h"

#define D_EXPLOSION 999

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
	int explosionTime;

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
	
	// ����
	void Explosion();

	//���e�̕`��
	void DrawBomb()const;
	//�����̕`��
	void DrawExplosion()const;


	int GetKey() { return key; }
};

