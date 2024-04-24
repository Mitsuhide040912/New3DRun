#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
#include "Enemy.h"
#include "Engine/SceneManager.h"
PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	Instantiate<Stage>(this);
	Instantiate<Player>(this);
	
}

void PlayScene::Update()
{
	Instantiate<Enemy>(this);
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}




