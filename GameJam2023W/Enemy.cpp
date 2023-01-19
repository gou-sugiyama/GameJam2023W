#include "DxLib.h"
#include "Enemy.h"
//--------------------
//�@�}�N����`
//--------------------

//-----------------------
//�@�萔�̐錾
//-----------------------

//-----------------------
//�@�ϐ��̐錾
//-----------------------

//�G�̉摜
int enemyImage[2];

//�G�p�ϐ�
int enemyType = 1;

//�G�̌��݂̗̑�
float enemyNowHp;

//�v���C���[HP�e�X�g�p
int playerHptst = 3;

//���e�_���[�W�e�X�g�p
int bomDmg = 1;

//--------------------
//�@�\����
//--------------------
typedef struct 
{
	float hp;	//�G��HP
}S_ENEMY_INFO;

//------------------------
// �@�G�l�~�[�e�[�u����`
//------------------------
const static S_ENEMY_INFO gEnemyTable[] =
{
	{2},
	{4},
};

//--------------------------
//�@�摜�Ǎ�
//--------------------------
int LoadEnemyImages(void)
{
	if ((enemyImage[0] = LoadGraph("�G/IMG_0415.PNG")) == -1)return-1;
	if ((enemyImage[1] = LoadGraph("�G/doragon.png")) == -1)return-1;
	//if ((enemyImage[2] = LoadGraph()) == -1)return-1;
	return 0;
}

//----------------------------
//�@�G�̕\��
//----------------------------
void DrawEnemy(void)
{
	DrawRotaGraph(600, 150, 0.5, 0.0, enemyImage[enemyType], TRUE);		//�G�̉摜�\��

	enemyNowHp = gEnemyTable[enemyType].hp;			//�G��HP�ݒ�
}

//----------------------------
//�@�G�̍U��
//----------------------------
void EnemyAttack(void)
{
	if (enemyNowHp > 0)
	{
		//�v���C���[�̎c�@-�P
		playerHptst = playerHptst - 1;		//�e�X�g�p

		if (playerHptst == 0) {
			DrawString(220, 220, "�I���",0x000000);
		}

	}
}

//------------------------------
//�@�G�̃_���[�W
//------------------------------
void EnemyDamage(void)
{

	int i;
	float enemyHp = 0;

	//�_���[�W�v�Z
	enemyNowHp = enemyNowHp-bomDmg;

	//�U������
	if (bomDmg > 0) {

		if (enemyNowHp > 0) {

			enemyHp = enemyNowHp / gEnemyTable[enemyType].hp;	//HP�̔䗦�v�Z

			//HP�Q�[�W�\��
			DrawBox(400, 250, 400 + 400 * enemyHp, 300, 0xff0000, TRUE);	//����
			DrawBox(400, 250, 800, 300, 0xffffff, FALSE);		//�O��
		}
	}
}