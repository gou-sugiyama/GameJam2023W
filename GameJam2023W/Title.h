#pragma once
#include "AbstractScene.h"

class Title : public AbstractScene {
private:
	int t = 0; //TODO:�����Ă�
	bool sceneFlg = false; //TODO:�����Ă�

public:
	Title();

	// �f�X�g���N�^
	~Title() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};
