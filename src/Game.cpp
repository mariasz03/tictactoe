#include "Game.hpp"
#include <iostream>

Game::Game(int size, int maxDepth, int winningLineLength) : board(size, winningLineLength), ai(maxDepth), size(size) {
    if (!circleTexture.loadFromFile("circle.png")) {
        std::cerr << "circle.png not loaded." << std::endl;
    }
    if (!crossTexture.loadFromFile("cross.png")) {
        std::cerr << "cross.png not loaded." << std::endl;
    }
    cellSize = 600 / size;
    circleSprite.setTexture(circleTexture);
    crossSprite.setTexture(crossTexture);
    float scale = static_cast<float>(cellSize) / circleTexture.getSize().x;
    circleSprite.setScale(scale, scale);
    crossSprite.setScale(scale, scale);
    cellShape.setSize(sf::Vector2f(cellSize, cellSize));
    cellShape.setFillColor(sf::Color::White);
    cellShape.setOutlineThickness(1);
    cellShape.setOutlineColor(sf::Color::Black);
}

StateOfField Game::playWithAI(sf::RenderWindow& window) {
    StateOfField currentPlayer = CIRCLE;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed && currentPlayer == CIRCLE) {
                int row = event.mouseButton.y / cellSize;
                int col = event.mouseButton.x / cellSize;
                if (board.makeMove(row, col, CIRCLE)) {
                    if (board.isWin(CIRCLE)) {
                        draw(window);
                        window.display();
                        sf::sleep(sf::seconds(3));
                        return CIRCLE;
                        window.close();
                    }
                    else if (board.isFull()) {
                        draw(window);
                        window.display();
                        sf::sleep(sf::seconds(3));
                        return NONE;
                        window.close();
                    }
                    currentPlayer = CROSS;
                }
            }
        }

        if (currentPlayer == CROSS) {
            Move bestMove = ai.findBestMove(board);
            board.setCell(bestMove.row, bestMove.col, CROSS);
            if (board.isWin(CROSS)) {
                draw(window);
                window.display();
                sf::sleep(sf::seconds(1));
                return CROSS;
                window.close();
            }
            else if (board.isFull()) {
                draw(window);
                window.display();
                sf::sleep(sf::seconds(1));
                return NONE;
                window.close();
        
            }
            currentPlayer = CIRCLE;
        }

        window.clear();
        draw(window);
        window.display();
    }
}

StateOfField Game::playWithHuman(sf::RenderWindow& window) {
    StateOfField currentPlayer = CIRCLE;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                int row = event.mouseButton.y / cellSize;
                int col = event.mouseButton.x / cellSize;
                if (board.makeMove(row, col, currentPlayer)) {
                    if (board.isWin(currentPlayer)) {
                        draw(window);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        return currentPlayer;
                        window.close();
                    }
                    else if (board.isFull()) {
                        draw(window);
                        window.display();
                        sf::sleep(sf::seconds(1));
                        return NONE;
                        window.close();
                    }
                    if (currentPlayer == CROSS) {
                        currentPlayer = CIRCLE;
                    } else if (currentPlayer == CIRCLE) {
                        currentPlayer = CROSS; 
                    }
                }
            }

        }

        window.clear();
        draw(window);
        window.display();
    }
}

void Game::draw(sf::RenderWindow& window) {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            cellShape.setPosition(j * cellSize, i * cellSize);
            window.draw(cellShape);
            if (board.getCell(i, j) == CIRCLE) {
                circleSprite.setPosition(j * cellSize, i * cellSize);
                window.draw(circleSprite);
            }
            else if (board.getCell(i, j) == CROSS) {
                crossSprite.setPosition(j * cellSize, i * cellSize);
                window.draw(crossSprite);
            }
        }
    }
}
