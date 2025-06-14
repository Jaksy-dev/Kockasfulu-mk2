#include "search.hpp"
#include "globals.hpp"
#include "evaluate.hpp"
#include "utils.hpp"

int negamax(Board &board, int depth)
{

    if (board.isHalfMoveDraw())
    {
        return board.getHalfMoveDrawType().first == GameResultReason::CHECKMATE ? LOSS_SCORE : DRAW_SCORE;
    }

    if (board.isRepetition())
    {
        return DRAW_SCORE;
    }

    Movelist moves;
    movegen::legalmoves(moves, board);

    if (moves.empty())
        return board.inCheck() ? LOSS_SCORE : DRAW_SCORE;

    if (depth == 0)
    {
        return board.sideToMove() == Color::WHITE ? evaluate(board) : -evaluate(board);
    }

    int maxscore = -INF;
    for (const auto & move : moves){
        board.makeMove(move);
        int score = -negamax(board, depth - 1);
        board.unmakeMove(move);
        if (score > maxscore){
            maxscore = score;
        }
    }

    return maxscore;
}

BestMove findBestMove(Board & board, int wtime, int btime, int winc, int binc)
{
    (void)wtime;
    (void)btime;
    (void)winc;
    (void)binc;

    Movelist moves;
    movegen::legalmoves(moves, board);

    BestMove bestMove{.move = Move::NO_MOVE, .score = -INF};

    for (const auto & move : moves){
        board.makeMove(move);
        int score = -negamax(board, DEPTH);
        board.unmakeMove(move);
        if (score > bestMove.score){
            bestMove.move = move;
            bestMove.score = score;
        }
    }

    return bestMove;
}
