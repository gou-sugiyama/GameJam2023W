#pragma once
#ifndef ENEMY_H
#define D_ENEMY_H
//----------------------------
#include "DxLib.h"
//----------------------------
//�@�}�N����`
//----------------------------


//----------------------------
//�@�^��`
//----------------------------
//typedef enum
//{

//}E_ENEMY_ID;

//----------------------------
//�@�֐��̃v���g�^�C�v�錾
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
