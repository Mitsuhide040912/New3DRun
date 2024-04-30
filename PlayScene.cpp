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
	
	/*switch (Rand) {
	case 0:
		for (int i = 0; i < 1; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space_, ObjectY_, EnemyZ_);
		}
		break;
	case 1:
		for (int i = 0; i < 2; i++)
		{
			Enemy* p = Instantiate<Enemy>(this);
			p->SetPosition(i + space_, ObjectY_, EnemyZ_);
		}
		break;
	case 2:
		Enemy * LEnemy = Instantiate<Enemy>(this);
		LEnemy->SetPosition(-0.5, ObjectY_, EnemyZ_);

		Enemy* REnemy = Instantiate<Enemy>(this);
		REnemy->SetPosition(1.5, ObjectY_, EnemyZ_);

		break;
	}*/
	
	
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




