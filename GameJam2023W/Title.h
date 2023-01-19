#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int SelectY;     //Y���W�̌���l
	bool sceneCHG;   //�V�[���ύX�l
	int OldY;
	int InputY;
	int FlgY;
	int SceneCHGCount;
	bool SceneCHGFlg;
	bool KeyFlg;

	int Titleimg;     //�^�C�g���C���[�W
	int TitleNameimg; //�^�C�g���l�[���C���[�W
	int Startimg;     //�X�^�[�g�C���[�W
	int Helpimg;      //�w���v�C���[�W
	int Endimg;       //�G���h�C���[�W
	int Carsorimg;    //�J�[�\���C���[�W

public:
	Title();

	// �f�X�g���N�^
	~Title() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

	void Flashing() const;  //�摜�̓_�ŏ���
	void Pad();
};
