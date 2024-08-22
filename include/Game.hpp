#ifndef GAME_HPP
#define GAME_HPP

#include "Board.hpp"
#include "AI.hpp"
#include <SFML/Graphics.hpp>

class Game {
public:
    Game(int size, int maxDepth, int winningLineLenghth);
    StateOfField playWithAI(sf::RenderWindow& window);
    StateOfField playWithHuman(sf::RenderWindow& window);

private:
    Board board;
    AI ai;
    void draw(sf::RenderWindow& window);
    int size;
    int cellSize;
    sf::Texture circleTexture;
    sf::Texture crossTexture;
    sf::Sprite circleSprite;
    sf::Sprite crossSprite;
    sf::RectangleShape cellShape;
};

#endif
