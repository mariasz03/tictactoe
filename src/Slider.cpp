#include "../include/Slider.hpp"
#include <iostream>

Slider::Slider(float x, float y, float width, int min, int max, int initial, int step, sf::Font& font, std::string labelText, sf::Color handleColor)
    : min(min), max(max), value(initial), step(step), font(font), isDragging(false) {
    track.setSize(sf::Vector2f(width, 5));
    track.setPosition(x, y);
    track.setFillColor(sf::Color::Black);

    handle.setSize(sf::Vector2f(10, 20));
    handle.setFillColor(handleColor);
    float handleX = x + (width * ((float)(initial - min) / (max - min))) - (handle.getSize().x / 2.f);
    handle.setPosition(handleX, y - 7.5);

    label.setFont(font);
    label.setString(labelText);
    label.setCharacterSize(18);
    label.setFillColor(sf::Color::Black);
    label.setPosition(x, y - 30);

    valueText.setFont(font);
    valueText.setCharacterSize(18);
    valueText.setFillColor(sf::Color::Black);
    updateValueText();
}

void Slider::update(const sf::Vector2f mousePosition, bool mousePressed) {
    if (mousePressed) {
        if (handle.getGlobalBounds().contains(mousePosition)) {
            isDragging = true;
            offsetX = mousePosition.x - handle.getPosition().x;
        }
    }
    else {
        isDragging = false;
    }

    if (isDragging) {
        float newX = mousePosition.x - offsetX;
        float trackStart = track.getPosition().x;
        float trackEnd = trackStart + track.getSize().x;

        if (newX < trackStart) newX = trackStart;
        if (newX > trackEnd - handle.getSize().x) newX = trackEnd - handle.getSize().x;

        float tickWidth = track.getSize().x / ((max - min) / step);
        float normalizedPosition = (newX - trackStart) / track.getSize().x;
        int nearestTick = std::round(normalizedPosition * ((max - min) / step));
        nearestTick = std::max(0, nearestTick);
        nearestTick = std::min((max - min) / step, nearestTick);

        handle.setPosition(trackStart + nearestTick * tickWidth, handle.getPosition().y);

        value = min + nearestTick * step;
        updateValueText();
    }
}

void Slider::render(sf::RenderTarget& target) {
    target.draw(track);
    drawTicks(target);
    target.draw(label);
    target.draw(handle);
    target.draw(valueText);
}

void Slider::updateValueText() {
    valueText.setString(std::to_string(value));
    valueText.setPosition(
        handle.getPosition().x + handle.getSize().x / 2.f - valueText.getGlobalBounds().width / 2.f,
        handle.getPosition().y + handle.getSize().y + 5);
}

void Slider::drawTicks(sf::RenderTarget& target) {
    float tickWidth = track.getSize().x / ((max - min) / step);
    for (int i = 0; i <= (max - min) / step; ++i) {
        float x = track.getPosition().x + i * tickWidth;
        sf::RectangleShape tick(sf::Vector2f(2, 10));
        tick.setPosition(x, track.getPosition().y + track.getSize().y / 2.f - tick.getSize().y / 2.f);
        tick.setFillColor(sf::Color::Black);
        target.draw(tick);
    }
}

void Slider::updateSliderValues(int min, int max, int initial, int step) {
    this->min = min;
    this->max = max;
    this->step = step;
    value = initial;
    // Update handle position
    float trackStart = track.getPosition().x;
    float trackWidth = track.getSize().x;
    float handleX = trackStart + (trackWidth * ((float)(initial - min) / (max - min))) - (handle.getSize().x / 2.f);
    handle.setPosition(handleX, handle.getPosition().y);

    updateValueText();

}