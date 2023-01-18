#pragma once
#include "common.h"
#include "T_Pos.h"

#define D_DIRECTION_UP {0,-1}
#define D_DIRECTION_RIGHT {1,0}
#define D_DIRECTION_DOWN {0,1}
#define D_DIRECTION_LEFT {1,0}

#define D_UNIT_SPEED 40

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
	T_Pos direction;
	const float pivotY = -10;
	const float pivotX = 8;
	float speedX;
	float speedY;
	int frame;
	bool deleteFlg;

	//�A�j���[�V�����p�ϐ�
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//�R���X�g���N�^
	Fire();
	Fire(T_Pos pos,T_Pos direction);
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

	//�ړ������idirection�j
	void DirectionalMove();

	//�ڕW���W�ƈړ����Ԃ̐ݒ�
	void SetTargetPos(T_Pos pos, int frame);

	//�\���̂̏�����
	void InitAnim();

	bool GetDeleteFlg() { return deleteFlg; }
	void SetFrame(int frame) { this->frame = frame; }
};

