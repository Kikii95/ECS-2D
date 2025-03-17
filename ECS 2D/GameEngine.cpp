#include "GameEngine.h"
#include "SystemRender.h"
#include "SystemPhysics.h"
#include "SystemCollision.h"
#include "ComponentTransform.h"
#include "ComponentRender.h"
#include "ComponentPhysics.h"
#include "ComponentCollider.h"
#include "ComponentInput.h"
#include "ComponentWeapon.h"
#include "ComponentTag.h"
#include "ComponentProjectile.h"




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

sf::RenderWindow& GameEngine::GetWindow() {
    return window;
}

GameTimer& GameEngine::GetTimer() {
    return gameTimer;
}

void GameEngine::Init() {
    window.create(sf::VideoMode(1280, 720), "SFML Game Engine");

    // Systems
    systemManager.AddSystem<SystemRender>();
    systemManager.AddSystem<SystemPhysics>();
    systemManager.AddSystem<SystemCollision>();

    // Player
    Entity* player = entityManager.CreateEntity();
    player->AddComponent<ComponentTransform>(sf::Vector2f(100, 500));
    player->AddComponent<ComponentRender>();
    player->AddComponent<ComponentPhysics>();
    player->AddComponent<ComponentCollider>(sf::Vector2f(50, 50), false);
    player->AddComponent<ComponentInput>();
    player->AddComponent<ComponentWeapon>(10, 1.5f, "bullet");
    player->AddComponent<ComponentTag>("PLAYER");

    // Wall
    Entity* wall = entityManager.CreateEntity();
    wall->AddComponent<ComponentTransform>(sf::Vector2f(400, 500));
    wall->AddComponent<ComponentRender>();
    wall->AddComponent<ComponentCollider>(sf::Vector2f(100, 100), false);
    wall->AddComponent<ComponentTag>("WALL");

    // Projectile
    Entity* projectile = entityManager.CreateEntity();
    projectile->AddComponent<ComponentTransform>(sf::Vector2f(200, 500));
    projectile->AddComponent<ComponentRender>();
    projectile->AddComponent<ComponentPhysics>();
    projectile->AddComponent<ComponentProjectile>(sf::Vector2f(1, 0), 800.0f, 10, 3.0f);
    projectile->AddComponent<ComponentCollider>(sf::Vector2f(10, 10), true);
    projectile->AddComponent<ComponentTag>("PROJECTILE");
}


void GameEngine::Run() {
    GameLoop();
}

void GameEngine::GameLoop() {
    while (window.isOpen()) {
        Logs::Get()->Init();
        ProcessEvents();
        gameTimer.Tick();
        float dt = gameTimer.DeltaTime();


        systemManager.Update(dt);

        window.clear(sf::Color::Black);

        systemManager.UpdateRender(dt);

        window.display();
    }
    Logs::Get()->UnInit();
}


void GameEngine::ProcessEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
    }

    // Moves
     Entity* player = entityManager.GetEntitiesByTag("PLAYER")[0];
    ComponentPhysics* physics = player->GetComponent<ComponentPhysics>();
    ComponentWeapon* weapon = player->GetComponent<ComponentWeapon>();

    sf::Vector2f velocity = physics->GetVelocity();
    bool moving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        velocity.x = -200;
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        velocity.x = 200;
        moving = true;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        velocity.y = -300;
        moving = true;
    }

    if (!moving) {
        velocity.x = 0;
    }

    physics->SetVelocity(velocity);

    // Shoot
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && weapon->CanFire()) {
        weapon->Fire(sf::Vector2f(1, 0));
    }
}


void GameEngine::CleanUp() {
    entityManager.Clear();
}
