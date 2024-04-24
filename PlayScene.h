#pragma once
#include <vector>
#include "Enemy.h"
#include "Engine/GameObject.h"

class PlayScene :
    public GameObject
{
    int Rand = rand() % 3;

    float ObjectY_ = 1.0;
    float EnemyZ_ = 1.0;
    float space_ = 0.5;
    
public:
    PlayScene(GameObject* parent);
    void Initialize()override;
    void Update()override;
    void Draw()override;
    void Release()override;

     //void placeEnemyRandomly(std::vector<Enemy>& enamies, int numEnemies);
};

