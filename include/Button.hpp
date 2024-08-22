#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
private:
	sf::RectangleShape shape;
	sf::Text text;
	sf::Color idleColor;
	sf::Color hoverColor;
	sf::Color idleTextColor;
	sf::Color hoverTextColor;

public:
	Button(float x, float y, float width, float height, sf::Font& font, std::string textString, unsigned int characterSize, sf::Color idleTextColor, sf::Color hoverTextColor, sf::Color idleColor, sf::Color hoverColor);
	~Button() {};
	void update(const sf::Vector2f mousePosition);
	void render(sf::RenderTarget& target);
	bool isClicked(const sf::Vector2f mousePosition);
};

#endif