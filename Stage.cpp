#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
#include "Engine/BoxCollider.h"
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hModel_(-1)
{
	SWidth_ = 3;
	SHeight_ = 80;
}

void Stage::Initialize()
{
	hModel_ = Model::Load("Model\\street3.fbx");
	assert(hModel_ >= 0);

	transform_.scale_.z -= 150;

	BoxCollider* collision = new BoxCollider(XMFLOAT3(0, 0, -20.0), XMFLOAT3(10, 10, 3.5));
	AddCollider(collision);

	Camera::SetPosition(XMFLOAT3(0.4, 3.5, -10.0));
	Camera::SetTarget(XMFLOAT3(0.4, -0.5, 10));
	//Camera::SetPosition({ 0.5,2.5,-2.0 });
	//Camera::SetTarget({ 0.5,2.0,0 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
	/*for (int z = 0; z < SHeight_; z++)
	{
		for (int x = 0; x < SWidth_; x++)
		{
			transform_.position_.x = x;
			transform_.position_.z = z;

			Model::SetTransform(hModel_, transform_);
			Model::Draw(hModel_);
		}
	}*/
}

void Stage::Release()
{
}

void Stage::OnCollision(GameObject* pTarget)
{
}
