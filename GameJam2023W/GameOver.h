#pragma once
#include "AbstractScene.h"
class GameOver :
	public AbstractScene
{
private:
	int cr;
	int a;
	int b;
	int GHandle;

public:
	//�R���X�g���N�^
	GameOver();

	//�f�X�g���N�^
	~GameOver() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

	void ten() const;
};

