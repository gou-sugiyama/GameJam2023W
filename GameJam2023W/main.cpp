#include "DxLib.h"
#include "common.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// �^�C�g���� test �ɕύX
	SetMainWindowText("GameJam2023Winter");

	ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

	SetGraphMode(D_SCREEN_WIDTH, D_SCREEN_HEIGHT, 32);

	if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

	SetMouseDispFlag(FALSE);	//�}�E�X�J�[�\����\��

	SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

	SetFontSize(20);		// �����T�C�Y��ݒ�

	// �Q�[�����[�v
	while (ProcessMessage() == 0 &&
		GetJoypadInputState(DX_INPUT_KEY_PAD1) != PAD_INPUT_9/*ESC�L�[*/ 
		)
	{
		ClearDrawScreen();

		DrawString(0, 0, "FirstCommit", 0xFFFFFF);

		ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
	}

	DxLib_End();	// DX���C�u�����g�p�̏I������

	return 0;	// �\�t�g�̏I��
}
