#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"),hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Player.fbx");
	assert(hModel_ >= 0);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		transform_.position_ = { -1,0,0 };
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		transform_.position_ = { 1,0,0 };
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
