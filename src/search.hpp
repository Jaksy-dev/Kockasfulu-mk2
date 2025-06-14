#pragma once
#include "utils.hpp"
#include <chess.hpp>

using namespace chess;

BestMove findBestMove(Board & board, int wtime, int btime, int winc, int binc);
