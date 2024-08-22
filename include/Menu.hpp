#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "Button.hpp"
#include "Slider.hpp"
#include "Checkbox.hpp"

class Menu {
private:
	sf::Color shapeColor;
	sf::Font font;
	sf::Text title;
	sf::RectangleShape shape;

public:
	Menu(float x, float y, float width, float height, sf::Font& font, std::string titleString, unsigned int characterSize);
	~Menu() {}
	void update(const sf::Vector2f mousePosition, bool mousePressed, bool mouseClicked);
	void render(sf::RenderTarget& target);
	int getSelectedSize() const {
		return sizeOfBoardSlider.getValue();
	}
	int getSelectedDepth() const {
		return aiDifficultySlider.getValue();
	}
	int getSelectedWinningLine() const {
		return sizeOfWinningLineSlider.getValue();
	}
	void updateWinningLineSlider();

	Button startButton;
	Button exitButton;
	Slider sizeOfBoardSlider;
	Slider sizeOfWinningLineSlider;
	Slider aiDifficultySlider;
	Checkbox checkBox;
};


#endif
