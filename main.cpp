#include <SFML/Graphics.hpp>
#include "include/Menu.hpp"
#include "include/Game.hpp"
#include "include/PopMessage.hpp"

const int WINDOW_SIZE = 600;

enum GameState {
    InMenu,
    InGame,
    GameOver
};

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_SIZE, WINDOW_SIZE), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);

    sf::Font font;
    if (!font.loadFromFile("monospace.ttf")) {
        return EXIT_FAILURE;
    }

    Menu menu(75, 30, 0.75 * WINDOW_SIZE, 0.9 * WINDOW_SIZE, font, "Tic Tac Toe", 50);
    PopMessage gameOverPopUp(75, 75, 0.75 * WINDOW_SIZE, 0.75 * WINDOW_SIZE, font, "Game over!", 30);

    GameState gameState = InMenu;
    StateOfField winner = NONE;

    int chosenSize;
    int chosenDepth;
    int chosenWinningLineLength;

    bool mousePressed = false;
    bool mouseClicked = false;
    bool redrawNeeded = true; 

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                mousePressed = true;
                mouseClicked = gameState == InMenu;
            }
            if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
                mousePressed = false;
            }
        }

        sf::Vector2i mousePos = sf::Mouse::getPosition(window);

        switch (gameState) {
        case InMenu:
            menu.update(sf::Vector2f(mousePos.x, mousePos.y), mousePressed, mouseClicked);
            redrawNeeded = true;

            if (mouseClicked) {
                if (menu.startButton.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) {
                    gameState = InGame;
                    chosenSize = menu.getSelectedSize();
                    chosenDepth = menu.getSelectedDepth();
                    chosenWinningLineLength = menu.getSelectedWinningLine();
                    redrawNeeded = true;
                }
                if (menu.exitButton.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) {
                    window.close();
                }
                mouseClicked = false;
            }
            break;

        case InGame: {
            std::cout << chosenWinningLineLength;
            Game game(chosenSize, chosenDepth, chosenWinningLineLength);
            if (menu.checkBox.isChecked()) {
                winner = game.playWithAI(window);
            }
            else {
                winner = game.playWithHuman(window);
            }
            gameState = GameOver;
            break;
        }
        case GameOver:
            switch (winner) {
            case CIRCLE:
                gameOverPopUp.setMessage("Circle won!");
                break;
            case CROSS:
                gameOverPopUp.setMessage("Cross won!");
                break;
            case NONE:
                gameOverPopUp.setMessage("It's a draw!");
                break;
            }
            gameOverPopUp.update(sf::Vector2f(mousePos.x, mousePos.y));
            if (gameOverPopUp.okButton.isClicked(sf::Vector2f(mousePos.x, mousePos.y))) gameState = InMenu;
            redrawNeeded = true;
        }

        if (redrawNeeded) {
            window.clear(sf::Color::White);
            if (gameState == InMenu) {
                menu.render(window);
            }
            else if (gameState == GameOver) {
                gameOverPopUp.render(window);
            }
            window.display();
            redrawNeeded = false;
        }
    }

    return 0;
}
