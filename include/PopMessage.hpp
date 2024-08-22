#ifndef POPMESSAGE_HPP
#define POPMESSAGE_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"

class PopMessage {
private:
    sf::Color shapeColor;
    sf::Font font;
    sf::Text text;
    sf::RectangleShape shape;

public:
    PopMessage(float x, float y, float width, float height, sf::Font& font, std::string text, unsigned int characterSize);
    ~PopMessage() {}
    void update(const sf::Vector2f mousePosition);
    void render(sf::RenderTarget& target);
    void setMessage(std::string text);
    Button okButton;
};

#endif