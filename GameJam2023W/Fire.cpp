#include "DxLib.h"
#include "Fire.h"

//--------------------
// �R���X�g���N�^
//--------------------
Fire::Fire()
{
	animTimer = 0;
	sparks1.anim = new T_Anim[2];
	sparks1.anim[0].image = LoadGraph("images/sparks/spark_1");
	sparks1.anim[0].next = 1;
	sparks1.anim[1].image = LoadGraph("images/sparks/spark_2");
	sparks1.anim[1].next = 0;
}

//--------------------
// �f�X�g���N�^
//--------------------


//--------------------
// �X�V
//--------------------
void Fire::Update()
{
	animTimer++;
}

//--------------------
// �`��
//--------------------
void Fire::Draw()const
{
	DrawRotaGraph(640,360,1.0/180*60,0,
		(*images).image,)
}
