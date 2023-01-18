#pragma once

//�A�j���[�V�����p
struct T_Image
{
	int image;
	int next;
};

struct T_Anim
{
	T_Image* sprites = nullptr;
	int current = 0;
};

class Fire
{
private:
	int x;
	int y;

	//�A�j���[�V�����p�ϐ�
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//�R���X�g���N�^
	Fire();
	//�f�X�g���N�^
	~Fire();

	//�X�V
	void Update();
	//�`��
	void Draw()const;
	
	//�A�j���[�V�����̍X�V
	void UpdateAnim();

	//�\���̂̏�����
	void InitAnim();
};

