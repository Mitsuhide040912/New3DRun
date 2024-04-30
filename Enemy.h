#pragma once
#include <vector>

#include "Engine/GameObject.h"
#include "Engine/BoxCollider.h"
class Enemy :
    public GameObject
{
    int hModel_;
    int y = 0;
    int z = 0;
    double speed_= 0.5;
    //int Rand = rand() % 3;
    int posZ_;
    float space_Z = 5.5f;
    const int NUM_OBJECTS = 15;
    int Lastlane_ = -1;
   
public:
    Enemy(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

    void OnCollision(GameObject* pTarget)override;
};

