#pragma once
#include "AbstractScene.h"

class Help : public AbstractScene
{
private:
	int SelectY;     //Y���W�̌���l
	int MenuY;       //�J�[�\����Y���W�̈ړ��l
	bool sceneCHG;   //�V�[���ύX�l

	int DebagCount;

	int Helpimg;
	int HelpBack;

public:
	Help();

	//�f�X�g���N�^
	~Help() {};

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};

