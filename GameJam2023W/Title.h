#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int SelectY;     //Y���W�̌���l
	bool sceneCHG;   //�V�[���ύX�l
	int OldY;
	int InputY;
	int FlgY;

	int DebagCount;

public:
	Title();

	// �f�X�g���N�^
	~Title() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

	void Pad();
};
