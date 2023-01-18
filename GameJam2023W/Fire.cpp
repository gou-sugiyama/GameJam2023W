#include "DxLib.h"
#include "Fire.h"

//--------------------
// �R���X�g���N�^
//--------------------
Fire::Fire()
{
	animTimer = 0;

	InitAnim();
}

//--------------------
// �f�X�g���N�^
//--------------------


//--------------------
// �X�V
//--------------------
void Fire::Update()
{
	UpdateAnim();

}

//--------------------
// �`��
//--------------------
void Fire::Draw()const
{
	for (int i = 0; i < 5; i++)
	{
		DrawRotaGraph(640, 360, 1.0 / 200 * 120, 0,
			sparks[i].sprites[sparks[i].current].image, TRUE);
	}

}

//------------------------------
// �A�j���[�V�����̍X�V
//------------------------------
void Fire::UpdateAnim()
{
	animTimer++;
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

	//fire.sprites = new int[3];

}