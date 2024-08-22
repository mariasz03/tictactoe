#include "AI.hpp"

AI::AI(int maxDepth) : maxDepth(maxDepth) {}

Move AI::findBestMove(Board& board) {
    int bestScore = std::numeric_limits<int>::min();
    Move bestMove;
    for (int i = 0; i < board.getSize(); ++i) {
        for (int j = 0; j < board.getSize(); ++j) {
            if (board.getCell(i, j) == NONE) {
                board.setCell(i, j, CROSS);
                int score = minimax(board, 0, false, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
                board.setCell(i, j, NONE);
                if (score > bestScore) {
                    bestScore = score;
                    bestMove = { i, j };
                }
            }
        }
    }
    return bestMove;
}

int AI::minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta) {
    if (board.isWin(CROSS)) return 10 - depth;
    if (board.isWin(CIRCLE)) return depth - 10;
    if (board.isFull() || depth >= maxDepth) return 0;

    if (isMaximizing) {
        int bestScore = std::numeric_limits<int>::min();
        for (int i = 0; i < board.getSize(); ++i) {
            for (int j = 0; j < board.getSize(); ++j) {
                if (board.getCell(i, j) == NONE) {
                    board.setCell(i, j, CROSS);
                    int score = minimax(board, depth + 1, false, alpha, beta);
                    board.setCell(i, j, NONE);
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, bestScore);
                    if (beta <= alpha) {
                        break; // Odciêcie beta
                    }
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = std::numeric_limits<int>::max();
        for (int i = 0; i < board.getSize(); ++i) {
            for (int j = 0; j < board.getSize(); ++j) {
                if (board.getCell(i, j) == NONE) {
                    board.setCell(i, j, CIRCLE);
                    int score = minimax(board, depth + 1, true, alpha, beta);
                    board.setCell(i, j, NONE);
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, bestScore);
                    if (beta <= alpha) {
                        break; // Odciêcie alfa
                    }
                }
            }
        }
        return bestScore;
    }
}
