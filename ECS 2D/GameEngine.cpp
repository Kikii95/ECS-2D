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
    player->AddComponent<ComponentInput>();
    player->AddComponent<ComponentTag>("PLAYER");
	player->AddComponent<ComponentCollider>();

    player->GetComponent<ComponentCollider>()->SetColliderSize(sf::Vector2f(100, 100));
	player->GetComponent<ComponentCollider>()->SetType(ColliderType::Solid);


    // Wall
    Entity* wall = entityManager.CreateEntity();
    wall->AddComponent<ComponentTransform>(sf::Vector2f(400, 500));
    wall->AddComponent<ComponentRender>();
    wall->AddComponent<ComponentTag>("WALL");
	wall->AddComponent<ComponentCollider>();

	wall->GetComponent<ComponentCollider>()->SetColliderSize(sf::Vector2f(100, 100));
    wall->GetComponent<ComponentCollider>()->SetType(ColliderType::Solid);


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

}


void GameEngine::CleanUp() {
    entityManager.Clear();
}
