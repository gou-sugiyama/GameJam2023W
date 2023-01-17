#include "padkey.h"

char padkey::old[BUTTONS];
char padkey::now[BUTTONS];
PADSTATE padkey::state = PADSTATE::NOT;
XINPUT_STATE padkey::Input;

void padkey::UpdataKey()
{
	GetJoypadXInputState(DX_INPUT_KEY_PAD1, &Input);
	for (int i = 0; i < BUTTONS; i++)
	{
		old[i] = now[i];
		now[i] = Input.Buttons[i];
	}
}
