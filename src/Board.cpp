#include "Board.hpp"

Board::Board(int size, int lineLength) : size(size), lineLength(lineLength), board(size, std::vector<StateOfField>(size, NONE)) {}

bool Board::makeMove(int row, int col, StateOfField player) {
    if (row >= 0 && row < size && col >= 0 && col < size && board[row][col] == NONE) {
        board[row][col] = player;
        return true;
    }
    return false;
}

bool Board::isFull() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (board[i][j] == NONE) return false;
        }
    }
    return true;
}



bool Board::isWin(StateOfField player) const {
    // Check rows
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j <= size - lineLength; ++j) {
            bool win = true;
            for (int k = 0; k < lineLength; ++k) {
                if (board[i][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check columns
    for (int i = 0; i <= size - lineLength; ++i) {
        for (int j = 0; j < size; ++j) {
            bool win = true;
            for (int k = 0; k < lineLength; ++k) {
                if (board[i + k][j] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonals (top-left to bottom-right)
    for (int i = 0; i <= size - lineLength; ++i) {
        for (int j = 0; j <= size - lineLength; ++j) {
            bool win = true;
            for (int k = 0; k < lineLength; ++k) {
                if (board[i + k][j + k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    // Check diagonals (top-right to bottom-left)
    for (int i = 0; i <= size - lineLength; ++i) {
        for (int j = lineLength - 1; j < size; ++j) {
            bool win = true;
            for (int k = 0; k < lineLength; ++k) {
                if (board[i + k][j - k] != player) {
                    win = false;
                    break;
                }
            }
            if (win) return true;
        }
    }

    return false;
}
StateOfField Board::getCell(int row, int col) const {
    return board[row][col];
}

void Board::setCell(int row, int col, StateOfField player) {
    board[row][col] = player;
}

int Board::getSize() const {
    return size;
}