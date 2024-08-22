#include "../include/PopMessage.hpp"

PopMessage::PopMessage(float x, float y, float width, float height, sf::Font& font, std::string text, unsigned int characterSize)
    : okButton(x + width / 2 - 75, y + height - 200, 150, 50, font, "OK", 20, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color(0, 204, 131)) {

    this->shapeColor = sf::Color::White;
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(sf::Vector2f(x, y));
    shape.setFillColor(shapeColor);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Black);

    this->text.setFont(font);
    this->text.setString(text);
    this->text.setCharacterSize(characterSize);
    this->text.setFillColor(sf::Color::Black);
    this->text.setPosition(
        shape.getPosition().x + (shape.getSize().x / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        shape.getPosition().y + (shape.getSize().y / 2.f) - (this->text.getGlobalBounds().height / 2.f) - 25);
};

void PopMessage::update(const sf::Vector2f mousePosition) {
    okButton.update(mousePosition);
};

void PopMessage::render(sf::RenderTarget& target) {
    target.draw(shape);
    target.draw(text);
    okButton.render(target);
};

void PopMessage::setMessage(std::string text) {
    this->text.setString(text);
    this->text.setPosition(
        shape.getPosition().x + (shape.getSize().x / 2.f) - (this->text.getGlobalBounds().width / 2.f),
        shape.getPosition().y + (shape.getSize().y / 2.f) - (this->text.getGlobalBounds().height / 2.f) - 25);
};