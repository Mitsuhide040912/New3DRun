#pragma once
#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"
class Player :
    public GameObject
{
    int hModel_;
    bool IsAlive_;
public:
    Player(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void OnCollision(GameObject* pTarget)override;
};

