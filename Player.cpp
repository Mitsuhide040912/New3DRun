#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/BoxCollider.h"
Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player1.fbx");
	assert(hModel_ >= 0);

	BoxCollider* colision = new BoxCollider(XMFLOAT3(0, 0, 0), XMFLOAT3(1.0, 1.0, 1.0));
	AddCollider(colision);
	transform_.position_ = XMFLOAT3(0.5, 0.5, 1.5);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_.x = -1;
	}
	else if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_.x = 1;
	}
	else
	{
		transform_.position_ = { 0,0,0 };
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	KillMe();
}
