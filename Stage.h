#pragma once
#include "Engine/GameObject.h"
class Stage :
    public GameObject
{
    int hModel_;
public:
    int SWidth_, SHeight_;
    Stage(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void OnCollision(GameObject* pTarget)override;
};

