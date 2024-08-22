#include "../include/Button.hpp"

Button::Button(float x, float y, float width, float height, sf::Font& font, std::string textString, unsigned int characterSize, sf::Color idleTextColor, sf::Color hoverTextColor, sf::Color idleColor, sf::Color hoverColor) {
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(x, y));
	shape.setFillColor(idleColor);


	text.setFont(font);
	text.setString(textString);
	text.setCharacterSize(characterSize);
	text.setFillColor(idleTextColor);
	text.setPosition(
		shape.getPosition().x + (shape.getSize().x / 2.f) - (text.getGlobalBounds().width / 2.f),
		shape.getPosition().y + (shape.getSize().y / 2.f) - (text.getGlobalBounds().height));
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(sf::Color::Black);
	this->idleColor = idleColor;
	this->hoverColor = hoverColor;
	this->idleTextColor = idleTextColor;
	this->hoverTextColor = hoverTextColor;
};

void Button::update(const sf::Vector2f mousePosition) {
	if (shape.getGlobalBounds().contains(mousePosition)) {
		shape.setFillColor(this->hoverColor);
		text.setFillColor(this->hoverTextColor);
	}
	else {
		shape.setFillColor(this->idleColor);
		text.setFillColor(this->idleTextColor);
	}
};

void Button::render(sf::RenderTarget& target) {
	target.draw(shape);
	target.draw(text);
};

bool Button::isClicked(const sf::Vector2f mousePosition) {
	return shape.getGlobalBounds().contains(mousePosition) && sf::Mouse::isButtonPressed(sf::Mouse::Left);
}