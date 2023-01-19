#pragma once

struct T_Pos
{
	float x;
	float y;

	T_Pos()
	{
		x = 0;
		y = 0;
	}

	T_Pos(float x, float y)
	{
		this->x = x;
		this->y = y;
	}

	T_Pos operator +(T_Pos pos)
	{
		T_Pos w;
		w.x = this->x + pos.x;
		w.y = this->y + pos.y;
		return w;
	}

	T_Pos operator -(T_Pos pos)
	{
		T_Pos w;
		w.x = this->x - pos.x;
		w.y = this->y - pos.y;
		return w;
	}

};
