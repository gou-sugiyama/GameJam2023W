#pragma once
class Bomb
{
private:
	int image;
	int x;
	int y;

public:
	//コンストラクタ　作られたときに呼ばれる
	Bomb();
	//デストラクタ　消されるときに呼ばれる
	~Bomb() {};

	//更新 ゲームメインで毎フレーム処理する
	void Update();
	//描画 描画するものは全部ここ
	void Draw()const;

	//爆弾の描画
	void DrawBomb()const;
};

