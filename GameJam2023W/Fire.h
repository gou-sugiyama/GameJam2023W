#pragma once

//アニメーション用
struct T_Image
{
	int image;
	int next;
};

struct T_Anim
{
	T_Image* sprites = nullptr;
	int current = 0;
};

class Fire
{
private:
	float x;
	float y;
	const float pivotY = -10;
	const float pivotX = 8;
	float speedX;
	float speedY;
	int frame;

	//アニメーション用変数
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//コンストラクタ
	Fire();
	Fire(float x, float y);
	//デストラクタ
	~Fire();

	//更新
	void Update();
	//描画
	void Draw()const;
	
	//アニメーションの更新
	void UpdateAnim();

	//移動処理
	void Move();

	//目標座標と移動時間の設定
	void SetTargetPos(float x, float y, int frame);

	//構造体の初期化
	void InitAnim();
};

