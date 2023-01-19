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
int enemyImage[2];

//敵用変数
int enemyType = 1;

//敵の現在の体力
float enemyNowHp;

//プレイヤーHPテスト用
int playerHptst = 3;

//爆弾ダメージテスト用
int bomDmg = 1;

//--------------------
//　構造体
//--------------------
typedef struct 
{
	float hp;	//敵のHP
}S_ENEMY_INFO;

//------------------------
// 　エネミーテーブル定義
//------------------------
const static S_ENEMY_INFO gEnemyTable[] =
{
	{2},
	{4},
};

//--------------------------
//　画像読込
//--------------------------
int LoadEnemyImages(void)
{
	if ((enemyImage[0] = LoadGraph("敵/IMG_0415.PNG")) == -1)return-1;
	if ((enemyImage[1] = LoadGraph("敵/doragon.png")) == -1)return-1;
	//if ((enemyImage[2] = LoadGraph()) == -1)return-1;
	return 0;
}

//----------------------------
//　敵の表示
//----------------------------
void DrawEnemy(void)
{
	DrawRotaGraph(600, 150, 0.5, 0.0, enemyImage[enemyType], TRUE);		//敵の画像表示

	enemyNowHp = gEnemyTable[enemyType].hp;			//敵のHP設定
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

	int i;
	float enemyHp = 0;

	//ダメージ計算
	enemyNowHp = enemyNowHp-bomDmg;

	//攻撃成功
	if (bomDmg > 0) {

		if (enemyNowHp > 0) {

			enemyHp = enemyNowHp / gEnemyTable[enemyType].hp;	//HPの比率計算

			//HPゲージ表示
			DrawBox(400, 250, 400 + 400 * enemyHp, 300, 0xff0000, TRUE);	//内側
			DrawBox(400, 250, 800, 300, 0xffffff, FALSE);		//外側
		}
	}
}