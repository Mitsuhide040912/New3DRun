#include "Enemy.h"
#include "Stage.h"
#include "Player.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Player1.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_.y = 90;
	
	/*switch (Rand) 
	{
	case 0:
		for (int i = -1; i < 1; i++)
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

	transform_.position_ = XMFLOAT3(0,0, 50.0);

	transform_.position_.x = rand() % 3-1;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0, 1.0, 1.0));
	AddCollider(collision);

	//if (transform_.position_.z < -5.0)
	//{
	//	transform_.position_ = {0, 0, 40.0};

	//	Model::SetTransform(hModel_, transform_);
	//	Model::Draw(hModel_);
	//}
	//else
	//{
	//	Model::SetTransform(hModel_, transform_);
	//	Model::Draw(hModel_);
	//}

	//for (int i = 0; i < transform_.position_.z - 10; i++)
	//{
	//	transform_.position_ = XMFLOAT3(0, 0, 50.0);
	//}
	
}

void Enemy::Update()
{
	
	transform_.position_.z -= speed_;

	//if (transform_.position_.z -= 0)
	//{
	//	KillMe();
	//}
}

void Enemy::Draw()
{
		Model::SetTransform(hModel_, transform_);
		Model::Draw(hModel_);
}

void Enemy::Release()
{
}

void Enemy::OnCollision(GameObject* pTarget)
{
	//transform_.position_ = (XMFLOAT3{ 0,0,50.0 });
	if (transform_.position_.z >= -6.0)
	{
		transform_.position_ = (XMFLOAT3{ 0,0,50.0 });
	}

	else
		KillMe();
}
