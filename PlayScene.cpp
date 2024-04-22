#include "PlayScene.h"
#include "Stage.h"
#include "Player.h"
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
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
