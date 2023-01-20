#pragma once
#include "DxLib.h"
#define Damege 5

class Player
{
private:
	int PlayerHp;
	int Attack[Damege] = { 1,2,3,4,5 };

protected:
	static int AttackDamege;

public:
	Player();
	~Player() {};
	static void Attacking();
	void DrawUI() const;
};

