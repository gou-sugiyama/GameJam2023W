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
	float x;
	float y;
	const float pivotY = -10;
	const float pivotX = 8;
	float speedX;
	float speedY;
	int frame;

	//�A�j���[�V�����p�ϐ�
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//�R���X�g���N�^
	Fire();
	Fire(float x, float y);
	//�f�X�g���N�^
	~Fire();

	//�X�V
	void Update();
	//�`��
	void Draw()const;
	
	//�A�j���[�V�����̍X�V
	void UpdateAnim();

	//�ړ�����
	void Move();

	//�ڕW���W�ƈړ����Ԃ̐ݒ�
	void SetTargetPos(float x, float y, int frame);

	//�\���̂̏�����
	void InitAnim();
};

