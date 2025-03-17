#pragma once

#include <SFML/Graphics.hpp>
#include "EntityManager.h"
#include "SystemManager.h"
#include "GameTimer.h"

class GameEngine {
public:
    static GameEngine& GetInstance();  // Singleton
    EntityManager& GetEntityManager();
    SystemManager& GetSystemManager();
    GameTimer& GetTimer();

    void Init();
    void Run();
    void CleanUp();

private:
    GameEngine() = default;  // Singleton
    ~GameEngine() = default;

    sf::RenderWindow window;  // Fenêtre SFML
    SystemManager systemManager;
    EntityManager entityManager;
    GameTimer gameTimer;

    bool isRunning = true;

    void ProcessEvents();
    void GameLoop();
};
