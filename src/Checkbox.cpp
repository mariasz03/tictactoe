#include "../include/Checkbox.hpp"

Checkbox::Checkbox(float x, float y, sf::Font& font, std::string labelText, bool checked, sf::Color innerBoxColor) : checked(checked), innerBoxColor(innerBoxColor) {
    box.setSize(sf::Vector2f(20, 20));
    box.setPosition(x+290, y);
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::Black);
    box.setFillColor(sf::Color::White);

    innerBox.setSize(sf::Vector2f(16, 16));
    innerBox.setPosition(x+292, y+2);
    innerBox.setFillColor(innerBoxColor);

    label.setFont(font);
    label.setString(labelText);
    label.setCharacterSize(20);
    label.setFillColor(sf::Color::Black);
    label.setPosition(x, y);
}

void Checkbox::update(const sf::Vector2f mousePosition, bool mouseClicked) {
    if (box.getGlobalBounds().contains(mousePosition) && mouseClicked) {
        checked = !checked;
    }
    if (checked) {
        innerBox.setFillColor(innerBoxColor);
    }
    else {
        innerBox.setFillColor(sf::Color::White);
    }
}

void Checkbox::render(sf::RenderTarget& target) {
    target.draw(box);
    target.draw(innerBox);
    target.draw(label);
}