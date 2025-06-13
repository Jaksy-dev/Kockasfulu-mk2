#include "search.hpp"
#include "globals.hpp"

BestMove bestMove(uint64_t wtime, uint64_t btime, uint64_t winc, uint64_t binc){
    (void)wtime;
    (void)btime;
    (void)winc;
    (void)binc;

    chess::Movelist movelist;
    chess::movegen::legalmoves(movelist, current_board);

    return {.eval=0, .move=movelist.front()};
}
