#include "../include/Menu.hpp"

Menu::Menu(float x, float y, float width, float height, sf::Font& font, std::string titleString, unsigned int characterSize)
	: startButton(150, 150, 300, 50, font, "START GAME", 20, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color(0, 204, 131)),
	exitButton(150, 500, 300, 50, font, "EXIT", 20, sf::Color::Black, sf::Color::White, sf::Color::White, sf::Color(0, 204, 131)),
	sizeOfBoardSlider(150, y + 225, 300, 3, 10, 3, 1, font, "Board size", sf::Color::Red),
	sizeOfWinningLineSlider(150, y + 300, 300, 2, 3, 3, 1, font, "Winning line length", sf::Color::Red),
	aiDifficultySlider(150, y + 425, 300, 0, 25, 1, 1, font, "AI Depth", sf::Color::Red),
	checkBox(150, y + 350, font, "Game with AI", false, sf::Color::Red) {
	this->shapeColor = sf::Color::White;
	shape.setSize(sf::Vector2f(width, height));
	shape.setPosition(sf::Vector2f(x, y));
	shape.setFillColor(shapeColor);
	shape.setOutlineThickness(1.f);
	shape.setOutlineColor(sf::Color::Black);

	title.setFont(font);
	title.setString(titleString);
	title.setCharacterSize(characterSize);
	title.setFillColor(sf::Color::Black);
	title.setPosition(
		shape.getPosition().x + (shape.getSize().x / 2.f) - (title.getGlobalBounds().width / 2.f),
		shape.getPosition().y + (shape.getSize().y / 2.f) - (title.getGlobalBounds().height / 2.f) - 225);
};

void Menu::update(const sf::Vector2f mousePosition, bool mousePressed, bool mouseClicked) {
	startButton.update(mousePosition);
	exitButton.update(mousePosition);
	sizeOfBoardSlider.update(mousePosition, mousePressed);
	if (sizeOfBoardSlider.getIsDragging()) updateWinningLineSlider();
	sizeOfWinningLineSlider.update(mousePosition, mousePressed);
	aiDifficultySlider.update(mousePosition, mousePressed);
	checkBox.update(mousePosition, mouseClicked);
};


void Menu::render(sf::RenderTarget& target) {
	target.draw(shape);
	target.draw(title);
	startButton.render(target);
	exitButton.render(target);
	sizeOfBoardSlider.render(target);
	sizeOfWinningLineSlider.render(target);
	if (checkBox.isChecked()) {
		aiDifficultySlider.render(target);
	}
	checkBox.render(target);
};
void Menu::updateWinningLineSlider() {
	sizeOfWinningLineSlider.updateSliderValues(2, sizeOfBoardSlider.getValue(), 3, 1);
}