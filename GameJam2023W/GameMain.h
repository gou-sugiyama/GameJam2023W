#pragma once
#include "AbstractScene.h"
class GameMain :
    public AbstractScene
{
private:
	int t = 0; //TODO:�����Ă�
	bool sceneFlg = false; //TODO:�����Ă�

public:
	//�R���X�g���N�^
	GameMain();

	//�f�X�g���N�^
	~GameMain() {}

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};

