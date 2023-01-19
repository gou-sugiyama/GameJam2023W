#pragma once
#include "AbstractScene.h"
#include "Fuses.h"
#include "Bomb.h"
class GameMain :
    public AbstractScene
{
private:
	Fuses* fuses;
	Bomb* bombs;
	bool sceneFlg = false; //TODO:�����Ă�

public:
	//�R���X�g���N�^
	GameMain();

	//�f�X�g���N�^
	~GameMain();

	void Update() override;						//�`��ȊO�̍X�V����
	void Draw() const override;					//�`��̍X�V����
	AbstractScene* ChangeScene() override;		//�V�[���̕ύX����
};

