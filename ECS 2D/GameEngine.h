#pragma once

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "SystemManager.h"
#include "GameTimer.h"


class GameEngine {
public:
    static GameEngine& GetInstance();
    EntityManager& GetEntityManager();
    SystemManager& GetSystemManager();
    sf::RenderWindow& GetWindow();
    GameTimer& GetTimer();

    void Init();
    void Run();
    void CleanUp();

private:
    GameEngine() = default; 
    ~GameEngine() = default;

    sf::RenderWindow window; 
    SystemManager systemManager;
    EntityManager entityManager;
    GameTimer gameTimer;

    bool isRunning = true;

    void ProcessEvents();
    void GameLoop();
};
