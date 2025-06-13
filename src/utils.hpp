#pragma once
#include <chess.hpp>

constexpr auto STARTER_FEN = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

struct BestMove
{
    uint64_t eval;
    chess::Move move;
};
