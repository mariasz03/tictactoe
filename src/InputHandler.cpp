#include "../include/InputHandler.hpp"

bool InputHandler::getMousePosition(sf::RenderWindow& window, int& x, int& y) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        x = pixelPos.x;
        y = pixelPos.y;
        return true;
    }
    return false;
}