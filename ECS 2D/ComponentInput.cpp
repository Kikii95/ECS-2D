#include "ComponentInput.h"

ComponentInput::ComponentInput(Entity* entity) : Component(entity) {
    keyBindings[InputAction::MOVE_LEFT] = sf::Keyboard::Q;
    keyBindings[InputAction::MOVE_RIGHT] = sf::Keyboard::D;
    keyBindings[InputAction::MOVE_UP] = sf::Keyboard::Z;
    keyBindings[InputAction::MOVE_DOWN] = sf::Keyboard::S;

    keyBindings[InputAction::JUMP] = sf::Keyboard::Space;
    keyBindings[InputAction::INTERACT] = sf::Keyboard::E;
    keyBindings[InputAction::SET] = sf::Keyboard::P;

    mouseBindings[InputAction::SHOOT] = sf::Mouse::Left;
}
