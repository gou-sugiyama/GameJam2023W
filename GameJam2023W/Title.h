#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int SelectY;     //Y���W�̌���l
	int MenuY;       //�J�[�\����Y���W�̈ړ��l
	bool sceneCHG;   //�V�[���ύX�l

	int DebagCount;
	//int GHandle;

public:
	Title();

	// �f�X�g���N�^
	~Title() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

	void Pad();
};
