#pragma once
#ifndef ENEMY_H
#define D_ENEMY_H
//----------------------------
#include "DxLib.h"
//----------------------------
//　マクロ定義
//----------------------------


//----------------------------
//　型定義
//----------------------------
//typedef enum
//{

//}E_ENEMY_ID;

//----------------------------
//　関数のプロトタイプ宣言
//----------------------------
void InitEnemy();
void DrawEnemy(void);
void EnemyAttack(void);
void EnemyDamage(void);
int LoadEnemyImages(void);
void DrawPlayerHp(void);
void RandomEnemy();
//----------------------------
#endif
