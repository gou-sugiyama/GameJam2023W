#pragma once
#include "common.h"
#include "T_Pos.h"

#define D_DIRECTION_UP {0,-1}
#define D_DIRECTION_RIGHT {1,0}
#define D_DIRECTION_DOWN {0,1}
#define D_DIRECTION_LEFT {1,0}

#define D_UNIT_SPEED 40

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
	T_Pos direction;
	const float pivotY = -10;
	const float pivotX = 8;
	float speedX;
	float speedY;
	int frame;
	bool deleteFlg;

	//アニメーション用変数
	int animTimer;
	T_Anim sparks[5];
	T_Anim fire = T_Anim();


public:
	//コンストラクタ
	Fire();
	Fire(T_Pos pos,T_Pos direction);
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

	//移動処理（direction）
	void DirectionalMove();

	//目標座標と移動時間の設定
	void SetTargetPos(T_Pos pos, int frame);

	//構造体の初期化
	void InitAnim();

	bool GetDeleteFlg() { return deleteFlg; }
	void SetFrame(int frame) { this->frame = frame; }
};

