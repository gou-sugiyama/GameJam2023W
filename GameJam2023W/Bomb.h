#pragma once
class Bomb
{
private:
	int image;
	int x;
	int y;

public:
	//�R���X�g���N�^�@���ꂽ�Ƃ��ɌĂ΂��
	Bomb();
	//�f�X�g���N�^�@�������Ƃ��ɌĂ΂��
	~Bomb() {};

	//�X�V �Q�[�����C���Ŗ��t���[����������
	void Update();
	//�`�� �`�悷����̂͑S������
	void Draw()const;

	//���e�̕`��
	void DrawBomb()const;
};

