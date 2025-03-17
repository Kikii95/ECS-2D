#include "Input.h"

std::map<sf::Keyboard::Key, bool> Input::keyState;
std::map<sf::Keyboard::Key, bool> Input::prevKeyState;

std::map<sf::Mouse::Button, bool> Input::mouseButtonState;
std::map<sf::Mouse::Button, bool> Input::prevMouseButtonState;

void Input::UpdateKeyState(sf::Keyboard::Key key, bool pressed) {
    prevKeyState[key] = keyState[key];
    keyState[key] = pressed;
}

void Input::UpdateMouseButtonState(sf::Mouse::Button button, bool pressed) {
    prevMouseButtonState[button] = mouseButtonState[button];
    mouseButtonState[button] = pressed;
}

bool Input::IsKeyPressed(sf::Keyboard::Key key) {
    return keyState[key];
}

bool Input::IsKeyReleased(sf::Keyboard::Key key) {
    return prevKeyState[key] && !keyState[key];
}

bool Input::IsMouseButtonPressed(sf::Mouse::Button button) {
    return mouseButtonState[button];
}

bool Input::IsMouseButtonReleased(sf::Mouse::Button button) {
    return prevMouseButtonState[button] && !mouseButtonState[button];
}

void Input::ProcessEvent(const sf::Event& event) {
    if (event.type == sf::Event::KeyPressed) {
        UpdateKeyState(event.key.code, true);
    }
    else if (event.type == sf::Event::KeyReleased) {
        UpdateKeyState(event.key.code, false);
    }
    else if (event.type == sf::Event::MouseButtonPressed) {
        UpdateMouseButtonState(event.mouseButton.button, true);
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        UpdateMouseButtonState(event.mouseButton.button, false);
    }
}

void Input::ResetInput() {
    keyState.clear();
    prevKeyState.clear();
    mouseButtonState.clear();
    prevMouseButtonState.clear();
}
