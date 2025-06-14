#pragma once
#include <chess.hpp>
#include <limits>

constexpr auto STARTER_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

constexpr auto INF = std::numeric_limits<int>::max();

constexpr auto DRAW_SCORE = 0;
constexpr auto WIN_SCORE = INF;
constexpr auto LOSS_SCORE = -INF;

struct BestMove
{
    chess::Move move;
    int score;
};
