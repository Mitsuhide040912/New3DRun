#include "TitleScene.h"
#include "Engine/Model.h"
#include "Engine/Image.h"
#include "Engine/SceneManager.h"
#include "Engine/Input.h"
TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene")
{
}

void TitleScene::Initialize()
{
	hImage_ = Image::Load("TitleScene.png");
	assert(hImage_ >= 0);
}

void TitleScene::Update()
{
	
	if (Input::IsKeyDown(DIK_SPACE))
	{

		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void TitleScene::Release()
{
}
