#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

enum StateOfField { NONE = 0, CIRCLE, CROSS };

class Board {
public:
    Board(int size, int lineLength);
    bool makeMove(int row, int col, StateOfField player);
    bool isFull() const;
    bool isWin(StateOfField player) const;
    StateOfField getCell(int row, int col) const;
    void setCell(int row, int col, StateOfField player);
    int getSize() const;
private:
    int size;
    int lineLength;
    std::vector<std::vector<StateOfField>> board;
};

#endif
