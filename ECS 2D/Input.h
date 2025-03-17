#pragma once
#include <SFML/Window.hpp>
#include <map>

class Input {
private:
    static std::map<sf::Keyboard::Key, bool> keyState;
    static std::map<sf::Keyboard::Key, bool> prevKeyState;

    static std::map<sf::Mouse::Button, bool> mouseButtonState;
    static std::map<sf::Mouse::Button, bool> prevMouseButtonState;

public:
    static void UpdateKeyState(sf::Keyboard::Key key, bool pressed);
    static void UpdateMouseButtonState(sf::Mouse::Button button, bool pressed);

    static bool IsKeyPressed(sf::Keyboard::Key key);
    static bool IsKeyReleased(sf::Keyboard::Key key);

    static bool IsMouseButtonPressed(sf::Mouse::Button button);
    static bool IsMouseButtonReleased(sf::Mouse::Button button);

    static void ProcessEvent(const sf::Event& event);
    static void ResetInput();
};
