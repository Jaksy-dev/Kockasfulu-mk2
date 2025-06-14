#include "evaluate.hpp"

int pieceValues(const Board &board)
{
    int score = 0;

    score += board.pieces(PieceType::PAWN, Color::WHITE).count() * 100;
    score += board.pieces(PieceType::KNIGHT, Color::WHITE).count() * 300;
    score += board.pieces(PieceType::BISHOP, Color::WHITE).count() * 300;
    score += board.pieces(PieceType::ROOK, Color::WHITE).count() * 500;
    score += board.pieces(PieceType::QUEEN, Color::WHITE).count() * 900;

    score -= board.pieces(PieceType::PAWN, Color::BLACK).count() * 100;
    score -= board.pieces(PieceType::KNIGHT, Color::BLACK).count() * 300;
    score -= board.pieces(PieceType::BISHOP, Color::BLACK).count() * 300;
    score -= board.pieces(PieceType::ROOK, Color::BLACK).count() * 500;
    score -= board.pieces(PieceType::QUEEN, Color::BLACK).count() * 900;

    return score;
}

int evaluate(Board &board)
{

    int score = 0;

    score += pieceValues(board);

    return score;
}
