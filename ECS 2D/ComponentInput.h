#pragma once
#include <SFML/Window.hpp>
#include <map>
#include "Component.h"

enum class InputAction {
    MOVE_LEFT,
    MOVE_RIGHT,
    MOVE_UP,
    MOVE_DOWN,
    SHOOT,
    JUMP,
    INTERACT,
    SET
};

class ComponentInput : public Component {
public:
    std::map<InputAction, sf::Keyboard::Key> keyBindings;
    std::map<InputAction, sf::Mouse::Button> mouseBindings;

    ComponentInput(Entity* entity);
};
