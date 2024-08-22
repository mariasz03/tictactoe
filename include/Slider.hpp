#ifndef SLIDER_HPP
#define SLIDER_HPP

#include <SFML/Graphics.hpp>

class Slider {
private:
    sf::RectangleShape track;
    sf::RectangleShape handle;
    sf::Color handleColor;
    sf::Text label;
    sf::Text valueText;
    sf::Font& font;
    int min;
    int max;
    int value;
    int step;
    bool isDragging;
    float offsetX;

public:
    Slider(float x, float y, float width, int min, int max, int initial, int step, sf::Font& font, std::string labelText, sf::Color handleColor);
    void update(const sf::Vector2f mousePosition, bool mousePressed);
    void render(sf::RenderTarget& target);
    int getValue() const {
        return value;
    }
    bool getIsDragging() const {
        return isDragging;
    }
    void updateSliderValues(int min, int max, int initial, int step);

private:
    void updateValueText();
    void drawTicks(sf::RenderTarget& target);
};

#endif // SLIDER_HPP
