#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Camera.h"
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage"), hModel_(-1)
{
	SWidth_ = 3;
	SHeight_ = 80;
}

void Stage::Initialize()
{
	hModel_ = Model::Load("Floor.fbx");
	assert(hModel_ >= 0);

	//transform_.scale_.z -= 50;

	Camera::SetPosition(XMFLOAT3(1, 2, -3.5));
	Camera::SetTarget(XMFLOAT3(1, 0, 10));
	//Camera::SetPosition({ 0.5,2.5,-2.0 });
	//Camera::SetTarget({ 0.5,2.0,0 });
}

void Stage::Update()
{
}

void Stage::Draw()
{
	//Model::SetTransform(hModel, transform_);
	//Model::Draw(hModel);
	for (int z = 0; z < SHeight_; z++)
	{
		for (int x = 0; x < SWidth_; x++)
		{
			transform_.position_.x = x;
			transform_.position_.z = z;

			Model::SetTransform(hModel_, transform_);
			Model::Draw(hModel_);
		}
	}
}

void Stage::Release()
{
}
