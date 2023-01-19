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
int enemyImage[3];
//int enemyImageDmg[3];

//�G�p�ϐ�
int enemyType = 1;

//�G�̌��݂̗̑�
float enemyNowHp;

//�v���C���[HP�e�X�g�p
int playerHptst = 3;

//���e�_���[�W�e�X�g�p
int bomDmg = 0;

int count=0;

int dmgFlg=0;

int take=0;

float enemyHp = 0;		//�̗͔䗦�p

int once = 0;

int enemyKillFlg = 0;
//--------------------
//�@�\����
//--------------------
typedef struct 
{
	float hp;	//�G��HP
}S_ENEMY_INFO;

//------------------------
// �@�G�l�~�[�e�[�u����`(�̗�)
//------------------------
const static S_ENEMY_INFO gEnemyTable[] =
{
	{2},
	{4},
	{10},
};

void InitEnemy() {
	enemyNowHp = gEnemyTable[enemyType].hp;			//�G��HP�ݒ�
}

//--------------------------
//�@�摜�Ǎ�
//--------------------------
int LoadEnemyImages(void)
{
	if ((enemyImage[0] = LoadGraph("�G/slime.png")) == -1)return-1;
	if ((enemyImage[1] = LoadGraph("�G/doragon.png")) == -1)return-1;
	//if ((enemyImageDmg[1] = LoadGraph("�G/doragon_dmg.png")) == -1)return-1;
	if ((enemyImage[2] = LoadGraph("�G/maou.png")) == -1)return-1;
	//if ((enemyImage[2] = LoadGraph()) == -1)return-1;
	return 0;
}

//----------------------------
//�@�G�̕\��
//----------------------------
void DrawEnemy(void)
{
	switch (enemyType)
	{
	case 0:			//�X���C��
		//�U������
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.4, 0.0, enemyImage[enemyType], TRUE);		//�G�̉摜�\��/�T�C�Y�E�ʒu(���S���W)�ύX
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		
		break;
	case 1:			//�h���S��
		//�U������
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.3, 0.0, enemyImage[enemyType], TRUE);		//�G�̉摜�\��/�T�C�Y�E�ʒu(���S���W)�ύX
			//DrawRotaGraph(626, 110, 0.3, 0.0, enemyImageDmg[enemyType], TRUE);	//�_���[�W�p�摜
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		break;
	case 2:			//����
		//�U������
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.7, 0.0, enemyImage[enemyType], TRUE);		//�G�̉摜�\��/�T�C�Y�E�ʒu(���S���W)�ύX
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		break;
	}
	//DrawRotaGraph(600, 100, 0.3, 0.0, enemyImage[enemyType], TRUE);		//�G�̉摜�\��

	if (enemyKillFlg != 0)
	{
		enemyNowHp = gEnemyTable[enemyType].hp;			//�G��HP�ݒ�
		enemyKillFlg = 0;
	}

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

	
		//�U������
	if (bomDmg >= 1) {
		DrawFormatString(0, 0, 0xffffff, "%lf", enemyNowHp);

		if (once == 0) {
			//�_���[�W�v�Z
			enemyNowHp = enemyNowHp - bomDmg;
			once = 1;
		}
		if (count++ <= 10) {
			switch (enemyType)
			{
			case 0:
				DrawRotaGraph(626, 110, 0.3, 0.0, enemyImage[enemyType], TRUE);
				break;
			case 1:
				DrawRotaGraph(626, 110, 0.25, 0.0, enemyImage[enemyType], TRUE);
				break;
			case 2:
				DrawRotaGraph(626, 110, 0.6, 0.0, enemyImage[enemyType], TRUE);
				break;
			}
		}
		else if (count++ <= 20) {

		}
		else {
			count = 0;
			take++;
		}

		if (take >= 2) {
			dmgFlg = 0;
			take = 0;
			once = 0;
			bomDmg = 0;
		}

	}
		
	if (enemyNowHp > 0) {

		enemyHp = enemyNowHp / gEnemyTable[enemyType].hp;	//HP�̔䗦�v�Z

		//HP�Q�[�W�\��
		DrawBox(426, 190, 413 + 413 * enemyHp, 160, 0xff00ff, TRUE);	//����
		DrawBox(426, 190, 826, 160, 0xffffff, FALSE);		//�O��
	}
	//---------------------
	// �G�؂�ւ�
	//---------------------
	
	if (enemyNowHp <= 0) {
		if (enemyType++ >= 2) {
			enemyType = 0;
		}
		bomDmg = 0;
		enemyKillFlg = 1;
		
	}
}