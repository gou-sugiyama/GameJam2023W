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
	int x;
	int y;

	//アニメーション用変数
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//コンストラクタ
	Fire();
	//デストラクタ
	~Fire();

	//更新
	void Update();
	//描画
	void Draw()const;
	
	//アニメーションの更新
	void UpdateAnim();

	//構造体の初期化
	void InitAnim();
};

