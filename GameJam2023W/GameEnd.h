#pragma once
#include "AbstractScene.h"

class GameEnd : public AbstractScene
{
private:
	int SelectY;     //Y���W�̌���l
	int MenuY;       //�J�[�\����Y���W�̈ړ��l
	bool sceneCHG;   //�V�[���ύX�l

	int DebagCount;

public:
	static int END;         //�I��

public:
	GameEnd();

	//�f�X�g���N�^
	~GameEnd() {};

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};

