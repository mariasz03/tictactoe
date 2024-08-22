#ifndef CHECKBOX_HPP
#define CHECKBOX_HPP

#include <SFML/Graphics.hpp> 
#include <iostream> 
class Checkbox {
private:
	sf::RectangleShape box;
	sf::RectangleShape innerBox;
	sf::Color innerBoxColor;
	sf::Text label;
	bool checked;

public:
	Checkbox(float x, float y, sf::Font& font, std::string labelText, bool checked = false, sf::Color innerBoxColor = sf::Color::Red);
	~Checkbox() {}

	void update(const sf::Vector2f mousePosition, bool mousePressed);
	void render(sf::RenderTarget& target);

	bool isChecked() const {
		return checked;
	}
};

#endif