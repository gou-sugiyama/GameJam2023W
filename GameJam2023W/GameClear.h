#pragma once
#include "AbstractScene.h"
class GameClear :
	public AbstractScene
{
private:
	int count;
	int GHandle;

public:
	//�R���X�g���N�^
	GameClear();

	//�f�X�g���N�^
	~GameClear() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����

	void ten() const;
};

