#pragma once

//�A�j���[�V�����p
struct T_Anim
{
	int image;
	int next;
};

struct T_Image
{
	T_Anim* anim = nullptr;
	int current = 0;
};

class Fire
{
private:
	int x;
	int y;

	//�A�j���[�V�����p�ϐ�
	int animTimer;
	T_Image sparks1 = T_Image();
	T_Image sparks2 = T_Image();
	T_Image sparks3 = T_Image();
	T_Image sparks4 = T_Image();
	T_Image sparks5 = T_Image();

	T_Image* images[5] =
	{
		sparks1,sparks2,sparks3,sparks4,sparks5
	};


public:
	//�R���X�g���N�^
	Fire();
	//�f�X�g���N�^
	~Fire() {};

	//�X�V
	void Update();
	//�`��
	void Draw()const;
	
};

