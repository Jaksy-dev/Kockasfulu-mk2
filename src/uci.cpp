#include "uci.hpp"

#include <chess.hpp>
#include <iostream>
#include "globals.hpp"
#include "utils.hpp"
#include "search.hpp"

namespace
{
    void parse_moves(std::istringstream &iss)
    {
        std::string moves;
        iss >> moves;
        std::string move;
        while (iss >> move)
        {
            current_board.makeMove(chess::uci::uciToMove(current_board, move));
        }
    }

    void position(std::istringstream &iss)
    {
        std::string fen_or_startpos;
        iss >> fen_or_startpos;
        if (fen_or_startpos == "fen")
        {
            std::string fenstring;
            for (int i = 0; i < 5; i++)
            {
                iss >> fenstring;
                fenstring.append(" ");
            }
            iss >> fenstring;

            current_board = chess::Board{fenstring};
            parse_moves(iss);
        }
        else if (fen_or_startpos == "startpos")
        {
            current_board = chess::Board{STARTER_FEN};
            parse_moves(iss);
        }
    }

    void go(std::istringstream & iss){
        std::string dummy;
        uint64_t wtime;
        uint64_t btime;
        uint64_t winc;
        uint64_t binc;
        iss >> dummy >> wtime >> dummy >> btime >> dummy >> winc >> dummy >> binc;

        auto bm = bestMove(wtime, btime, winc, binc);

        std::cout << "info score cp " << bm.eval << "\n";
        std::cout << "bestmove " << chess::uci::moveToUci(bm.move) << "\n";
    }
}

void parse_command(std::string &line)
{
    std::istringstream iss{line};
    std::string command;
    iss >> command;
    if (command == "uci")
    {
        // @TODO: separate function
        std::cout << "id Kockasfulu-mk2\n"; // @TODO: add options
        std::cout
            << "uciok\n";
    }
    if (command == "isready")
    {
        std::cout << "readyok\n";
    }
    if (command == "ucinewgame")
    {
        current_board = chess::Board{STARTER_FEN};
    }
    if (command == "position")
    {
        position(iss);
    }
    if (command == "go"){
        go(iss);
    }
    if (command == "stop"){
        exit(0);
    }
}
