#pragma once
#include "AbstractScene.h"
class GameClear :
	public AbstractScene
{
private:
	int t = 0; //TODO:�����Ă�
	bool sceneFlg = false; //TODO:�����Ă�
	int count;

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

