#pragma once
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"
class Enemy :
    public GameObject
{
    int hModel_;
    double speed_=0.50f;
public:
    Enemy(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void OnCollision(GameObject* pTarget)override;
};

