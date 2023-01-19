#include "DxLib.h"
#include "Enemy.h"
//--------------------
//　マクロ定義
//--------------------

//-----------------------
//　定数の宣言
//-----------------------

//-----------------------
//　変数の宣言
//-----------------------

//敵の画像
int enemyImage[3];
//int enemyImageDmg[3];

//敵用変数
int enemyType = 1;

//敵の現在の体力
float enemyNowHp;

//プレイヤーHPテスト用
int playerHptst = 3;

//爆弾ダメージテスト用
int bomDmg = 0;

int count=0;

int dmgFlg=0;

int take=0;

float enemyHp = 0;		//体力比率用

int once = 0;

int enemyKillFlg = 0;
//--------------------
//　構造体
//--------------------
typedef struct 
{
	float hp;	//敵のHP
}S_ENEMY_INFO;

//------------------------
// 　エネミーテーブル定義(体力)
//------------------------
const static S_ENEMY_INFO gEnemyTable[] =
{
	{2},
	{4},
	{10},
};

void InitEnemy() {
	enemyNowHp = gEnemyTable[enemyType].hp;			//敵のHP設定
}

//--------------------------
//　画像読込
//--------------------------
int LoadEnemyImages(void)
{
	if ((enemyImage[0] = LoadGraph("敵/slime.png")) == -1)return-1;
	if ((enemyImage[1] = LoadGraph("敵/doragon.png")) == -1)return-1;
	//if ((enemyImageDmg[1] = LoadGraph("敵/doragon_dmg.png")) == -1)return-1;
	if ((enemyImage[2] = LoadGraph("敵/maou.png")) == -1)return-1;
	//if ((enemyImage[2] = LoadGraph()) == -1)return-1;
	return 0;
}

//----------------------------
//　敵の表示
//----------------------------
void DrawEnemy(void)
{
	switch (enemyType)
	{
	case 0:			//スライム
		//攻撃成功
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.4, 0.0, enemyImage[enemyType], TRUE);		//敵の画像表示/サイズ・位置(中心座標)変更
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		
		break;
	case 1:			//ドラゴン
		//攻撃成功
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.3, 0.0, enemyImage[enemyType], TRUE);		//敵の画像表示/サイズ・位置(中心座標)変更
			//DrawRotaGraph(626, 110, 0.3, 0.0, enemyImageDmg[enemyType], TRUE);	//ダメージ用画像
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		break;
	case 2:			//魔王
		//攻撃成功
		if (bomDmg > 0) {
			dmgFlg = 1;
		}
		if (dmgFlg != 1) {
			DrawRotaGraph(626, 110, 0.7, 0.0, enemyImage[enemyType], TRUE);		//敵の画像表示/サイズ・位置(中心座標)変更
			if (60 < count++) {
				bomDmg = 1;
				count = 0;
			}
		}
		break;
	}
	//DrawRotaGraph(600, 100, 0.3, 0.0, enemyImage[enemyType], TRUE);		//敵の画像表示

	if (enemyKillFlg != 0)
	{
		enemyNowHp = gEnemyTable[enemyType].hp;			//敵のHP設定
		enemyKillFlg = 0;
	}

}

//----------------------------
//　敵の攻撃
//----------------------------
void EnemyAttack(void)
{
	if (enemyNowHp > 0)
	{
		//プレイヤーの残機-１
		playerHptst = playerHptst - 1;		//テスト用

		if (playerHptst == 0) {
			DrawString(220, 220, "終わり",0x000000);
		}

	}
}

//------------------------------
//　敵のダメージ
//------------------------------
void EnemyDamage(void)
{

	
		//攻撃成功
	if (bomDmg >= 1) {
		DrawFormatString(0, 0, 0xffffff, "%lf", enemyNowHp);

		if (once == 0) {
			//ダメージ計算
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

		enemyHp = enemyNowHp / gEnemyTable[enemyType].hp;	//HPの比率計算

		//HPゲージ表示
		DrawBox(426, 190, 413 + 413 * enemyHp, 160, 0xff00ff, TRUE);	//内側
		DrawBox(426, 190, 826, 160, 0xffffff, FALSE);		//外側
	}
	//---------------------
	// 敵切り替え
	//---------------------
	
	if (enemyNowHp <= 0) {
		if (enemyType++ >= 2) {
			enemyType = 0;
		}
		bomDmg = 0;
		enemyKillFlg = 1;
		
	}
}