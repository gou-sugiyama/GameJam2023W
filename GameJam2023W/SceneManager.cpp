#include "SceneManager.h"
#include"Title.h"

//----------------------
// コンストラクタ
//----------------------
SceneManager::SceneManager()
{
	mScene = new Title();
}

// メンバ変数の値を書き換えるアップデート関数
void SceneManager::Update() {
	mScene->Update();
	this->ChangeScene();
}

// 描画処理のみを行う関数
void SceneManager::Draw() const 
{
	mScene->Draw();
}

//-----------------------
// シーンの切り替え
//-----------------------
AbstractScene* SceneManager::ChangeScene()
{
	AbstractScene* nextScene = mScene;
	nextScene = mScene->ChangeScene();

	// 次のシーンが現在シーンと違う場合切り替える
	if (nextScene != mScene) {
		delete mScene;
		mScene = nextScene;
	}

	return nextScene;
}