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
	hModel_ = Model::Load("Model\\character-orc.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = XMFLOAT3(0.015f, 0.015f, 0.015f);
	transform_.rotate_.y = 180;

	transform_.position_ = XMFLOAT3(0.0,0.0, 50.0);

    transform_.position_.x = (rand() % 3 - 1) % 3;
	//Lastlane_ = Rand;
	
	

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0, 1.0, 1.0));
	
	AddCollider(collision);
	
	
}

void Enemy::Update()
{
	
	/*for (int i = 0; i < NUM_OBJECTS; i++)
	{
		float posZ = i - space_Z;
		
		
	}*/
	
	
	XMVECTOR f = { 0.0f,0.0f,5.0f };
	transform_.position_.z -= speed_;
	//transform_.position_.z -= space_Z;
	
	
	//transform_.position_ = (XMFLOAT3{ 0,0,50.0 });
	if (transform_.position_.z <= -1.0)
	{
		//transform_.position_ = (XMFLOAT3{ 0,0,-50.0 });
		KillMe();
	}
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
}
