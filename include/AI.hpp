#ifndef AI_HPP
#define AI_HPP

#include "Board.hpp"
#include <limits>
#include <cstdlib>
#include <ctime>
#include <algorithm>

struct Move { int row, col; };

class AI {
public:
    AI(int maxDepth);
    Move findBestMove(Board& board);

private:
    int maxDepth;
    int minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);
};

#endif
