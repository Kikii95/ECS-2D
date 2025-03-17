#pragma once
#include <SFML/System.hpp>

class GameTimer {
public:
    GameTimer();

    float TotalTime() const;
    float DeltaTime() const;

    void Reset();
    void Start();
    void Stop();
    void Tick();

private:
    sf::Clock clock;
    sf::Time previousTime;
    sf::Time deltaTime;
    bool stopped;
};
