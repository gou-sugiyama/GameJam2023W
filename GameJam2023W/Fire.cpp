#include "DxLib.h"
#include "Fire.h"

//--------------------
// �R���X�g���N�^
//--------------------
Fire::Fire()
{
	x = 600;
	y = 360;
	speedX = 0;
	speedY = 0;
	frame = 0;

	animTimer = 0;

	InitAnim();
}

//-------------------
// �R���X�g���N�^
//-------------------
Fire::Fire(float x, float y)
{
	this->x = x;
	this->y = y;
	speedX = 0;
	speedY = 0;
	frame = 0;

	animTimer = 0;

	InitAnim();
}

//--------------------
// �f�X�g���N�^
//--------------------
Fire::~Fire()
{
	for (int i = 0; i < 5; i++)
	{
		delete[] sparks[i].sprites;
	}
	delete[] fire.sprites;
}


//--------------------
// �X�V
//--------------------
void Fire::Update()
{
	UpdateAnim();
	Move();
	if (frame > 0)
	{
		frame--;
	}
	else
	{
		speedX = 0;
		speedY = 0;
	}

}

//--------------------
// �`��
//--------------------
void Fire::Draw()const
{

	DrawRotaGraphF(x + pivotX , y + pivotY, 1.0 / 200 * 160, 0,
		fire.sprites[fire.current].image, TRUE);

	for (int i = 0; i < 5; i++)
	{
		DrawRotaGraphF(x + pivotX, y + pivotY, 1.0 / 200 * 140, 0,
			sparks[i].sprites[sparks[i].current].image, TRUE);
	}

}

//------------------------------
// �A�j���[�V�����̍X�V
//------------------------------
void Fire::UpdateAnim()
{
	animTimer++;

	//�ΉԂ̍X�V
	if (animTimer % 20 == 0)
	{
		sparks[0].current = sparks[0].sprites[sparks[0].current].next;
	}

	if (animTimer % 15 == 0)
	{
		sparks[1].current = sparks[1].sprites[sparks[1].current].next;
	}
	
	if (animTimer % 10 == 0)
	{
		sparks[2].current = sparks[2].sprites[sparks[2].current].next;
	}
	
	if (animTimer % 7 == 0)
	{
		sparks[3].current = sparks[3].sprites[sparks[3].current].next;
	}

	if (animTimer % 4 == 0)
	{
		sparks[4].current = sparks[4].sprites[sparks[4].current].next;
	}

	//�΂̍X�V
	if (animTimer % 15 == 0)
	{
		fire.current = fire.sprites[fire.current].next;
	}
}

//-----------------------
// �ړ�����
//-----------------------
void Fire::Move()
{
	x += speedX;
	y += speedY;
}

//----------------------------------------------------------------------
// �ڕW���W�ƈړ����Ԃ̐ݒ�@�����F���Wxy �ړ��ɂ�����t���[����
//----------------------------------------------------------------------
void Fire::SetTargetPos(float x, float y, int frame)
{
	float distanceX = x - this->x;
	float distanceY = y - this->y;

	speedX = distanceX / frame;
	speedY = distanceY / frame;

	this->frame = frame;
}

//------------------------------
// �\���̂̏�����
//------------------------------
void Fire::InitAnim()
{
	for (int i = 0; i < 5; i++)
	{
		sparks[i] = T_Anim();
	}

	sparks[0].sprites = new T_Image[2];
	sparks[0].sprites[0].image = LoadGraph("images/sparks/spark_1.png");
	sparks[0].sprites[0].next = 1;
	sparks[0].sprites[1].image = LoadGraph("images/sparks/spark_2.png");
	sparks[0].sprites[1].next = 0;
	
	sparks[1].sprites = new T_Image[2];
	sparks[1].sprites[0].image = LoadGraph("images/sparks/spark_3.png");
	sparks[1].sprites[0].next = 1;
	sparks[1].sprites[1].image = LoadGraph("images/sparks/spark_4.png");
	sparks[1].sprites[1].next = 0;
	
	sparks[2].sprites = new T_Image[2];
	sparks[2].sprites[0].image = LoadGraph("images/sparks/spark_5.png");
	sparks[2].sprites[0].next = 1;
	sparks[2].sprites[1].image = LoadGraph("images/sparks/spark_6.png");
	sparks[2].sprites[1].next = 0;
	
	sparks[3].sprites = new T_Image[2];
	sparks[3].sprites[0].image = LoadGraph("images/sparks/spark_7.png");
	sparks[3].sprites[0].next = 1;
	sparks[3].sprites[1].image = LoadGraph("images/sparks/spark_8.png");
	sparks[3].sprites[1].next = 0;
	
	sparks[4].sprites = new T_Image[2];
	sparks[4].sprites[0].image = LoadGraph("images/sparks/spark_9.png");
	sparks[4].sprites[0].next = 1;
	sparks[4].sprites[1].image = LoadGraph("images/sparks/spark_10.png");
	sparks[4].sprites[1].next = 0;

	fire.sprites = new T_Image[4];
	fire.sprites[0].image = LoadGraph("images/fires/fire_1.png");
	fire.sprites[0].next = 1;
	fire.sprites[1].image = LoadGraph("images/fires/fire_2.png");
	fire.sprites[1].next = 2;
	fire.sprites[2].image = LoadGraph("images/fires/fire_3.png");
	fire.sprites[2].next = 3;
	fire.sprites[3].image = fire.sprites[1].image;
	fire.sprites[3].next = 0;

}