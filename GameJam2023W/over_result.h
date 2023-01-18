#pragma once
#include "AbstractScene.h"
class over_result:public AbstractScene
{
private:
	int a;
	int b;
	int cr;
	bool sceneFlg;
	int count;
	int GHandle;

public:
	over_result();
	~over_result() {}
	void Update() override;
	void Draw() const override;
	void ten() const;
	AbstractScene* ChangeScene() override;
};

