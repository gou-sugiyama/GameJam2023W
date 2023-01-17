#pragma once
#include"DxLib.h"

#define BUTTONS 16
#define MARGIN  32767*0.25

enum class PADSTATE
{
	NOT = 0,
	ON,
	DOWN
};

class padkey
{
private:
	static char old[BUTTONS];
	static char now[BUTTONS];
	static PADSTATE state;
	static XINPUT_STATE Input;

	padkey() = default;

public:
	static void UpdataKey();
	static int GetPadThumblX() { return Input.ThumbLX; }
	static int GetPadThumblY() { return Input.ThumbLY; }

	static bool OnClick(int inputkey)
	{
		bool ret = (now[inputkey] == 1 && old[inputkey] == 0);
		return ret;
	}
	static bool OnPressed(int inputkey)
	{
		bool ret = (now[inputkey] == 1);
		return ret;
	}
	static bool OnRelease(int inputkey)
	{
		bool ret = (now[inputkey] == 0 && old[inputkey] == 1);
		return ret;
	}
};

