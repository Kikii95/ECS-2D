#include "GameEngine.h"

GameEngine& GameEngine::GetInstance() {
    static GameEngine instance;
    return instance;
}

EntityManager& GameEngine::GetEntityManager() {
    return entityManager;
}

SystemManager& GameEngine::GetSystemManager() {
    return systemManager;
}

GameTimer& GameEngine::GetTimer() {
    return gameTimer;
}

void GameEngine::Init() {
    window.create(sf::VideoMode(1280, 720), "SFML Game Engine");
    //systemManager.AddSystem<SystemRender>();
    //systemManager.AddSystem<SystemPhysics>();
    //systemManager.AddSystem<SystemInput>();
}

void GameEngine::Run() {
    GameLoop();
}

void GameEngine::GameLoop() {
    while (window.isOpen()) {
        ProcessEvents();
        gameTimer.Tick();
        float dt = gameTimer.DeltaTime();

        systemManager.Update(dt);

        window.clear();
        systemManager.UpdateRender(dt);
        window.display();
    }
}

void GameEngine::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void GameEngine::CleanUp() {
    entityManager.Clear();
}
