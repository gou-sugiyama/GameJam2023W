#include "Player.h"
#include "Enemy.h"
#include <math.h>
#include "Bomb.h"

int Player::AttackDamege;

Player::Player() {
	PlayerHp = 10;
	AttackDamege = Attack[GetRand(Damege)];
}

void Player::Attacking() {
	EnemyDamage(AttackDamege, true);
	Bomb::AttackFlg = false;
}

void Player::DrawUI() const {
	
}