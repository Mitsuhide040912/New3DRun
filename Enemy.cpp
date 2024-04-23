#include "Enemy.h"
#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/BoxCollider.h"
Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy"),hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	transform_.rotate_.y = 90;
	
	transform_.position_ = XMFLOAT3(0,-0.2, 50.0);

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0, 1.0, 1.0));
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= speed_;
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
	transform_.position_ = (XMFLOAT3{ 0,0,50.0 });
}
