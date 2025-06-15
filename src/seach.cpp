#include "search.hpp"
#include "globals.hpp"
#include "evaluate.hpp"
#include "utils.hpp"

/*function negamax(node, depth, α, β, color) is
    alphaOrig := α

    (* Transposition Table Lookup; node is the lookup key for ttEntry *)
    ttEntry := transpositionTableLookup(node)
    if ttEntry.is_valid and ttEntry.depth ≥ depth then
        if ttEntry.flag = EXACT then
            return ttEntry.value
        else if ttEntry.flag = LOWERBOUND and ttEntry.value ≥ beta then
            return ttEntry.value
        else if ttEntry.flag = UPPERBOUND and ttEntry.value ≤ alpha then
            return ttEntry.value

    if depth = 0 or node is a terminal node then
        return color × the heuristic value of node

    childNodes := generateMoves(node)
    childNodes := orderMoves(childNodes)
    value := −∞
    for each child in childNodes do
        value := max(value, −negamax(child, depth − 1, −β, −α, −color))
        α := max(α, value)
        if α ≥ β then
            break

    (* Transposition Table Store; node is the lookup key for ttEntry *)
    ttEntry.value := value
    if value ≤ alphaOrig then
        ttEntry.flag := UPPERBOUND
    else if value ≥ β then
        ttEntry.flag := LOWERBOUND
    else
        ttEntry.flag := EXACT
    ttEntry.depth := depth
    ttEntry.is_valid := true
    transpositionTableStore(node, ttEntry)

    return value*/

int negamax(Board &board, int depth, int alpha, int beta)
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
        int score = std::max(maxscore, -negamax(board, depth - 1, -beta, -alpha));
        board.unmakeMove(move);
        if (score > maxscore){
            maxscore = score;
        }
        alpha = std::max(alpha, score);
        if (alpha >= beta){
            break;
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

    const int alpha = -INF;
    const int beta = INF;

    for (const auto & move : moves){
        board.makeMove(move);
        int score = -negamax(board, DEPTH, alpha, beta);
        board.unmakeMove(move);
        if (score > bestMove.score){
            bestMove.move = move;
            bestMove.score = score;
        }
    }

    return bestMove;
}
