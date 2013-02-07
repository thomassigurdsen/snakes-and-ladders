/*
 * main.cpp
 *
 * Copyright 2012 Thomas Sigurdsen <thomas.sigurdsen@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 */
#include <stdio.h>
#include <random>

struct Tile {
    int chute;
};

const int DEBUG = 2;
const int MAXTURNS = 1000;

class GMClass {
public:
    Tile *board;
    std::random_device rnd;
    GMClass(int size);
    void rungame(int);
    ~GMClass();
};

GMClass::~GMClass() {
    delete board;
}

GMClass::GMClass(int size) {
    std::random_device rnd;
    if (DEBUG > 1) {
        auto nm = rnd() % 6 + 1;
        printf("%d\n",nm);
    }
    board = new Tile[size];
    /* Generate board */
    for (int tcnt = size; tcnt > 0; --tcnt) {
//        board[tcnt] = new Tile;
        if ((tcnt > 12)) {
            if ((rnd() % 20) == 7) {
                int rndnum = rnd() % (tcnt - 10) + 1;
                if (rndnum < 0)
                    rndnum = 0;
                board[tcnt].chute = rndnum;
            } else {
                board[tcnt].chute = 0;
            }
        }
    }
}

void GMClass::rungame(int mapsize) {
    if (DEBUG > 1)
        printf("mapsize: %d\n",mapsize);
    int player = 0;
    int turns = 0;
    /* play the game */
    while (turns < MAXTURNS) {
        if (DEBUG > 1)
            printf("turns: %d, player: %d\r",turns,player);
        turns++;
        player += rnd() % 6 + 1;
        if ((player < mapsize) && (board[player].chute)) {
            player = board[player].chute;
        }
        if (DEBUG > 1)
            printf("turns: %d, player: %d\n",turns,player);
        if (player > mapsize)
            break;
    }
    printf("%d\n",turns);
}

int main(int argc, char **argv) {
    if (argc == 1) {
       printf("Error: too few arguments, I need a number of tiles\n");
       return -1;
    }
    GMClass game(atoi(argv[1]));
    if (DEBUG > 1)
         printf("%s\n",argv[1]);
    if (DEBUG > 1) {
        auto nm = game.rnd() % 6 + 1;
        printf("%d\n",nm);
    }
    if (DEBUG > 1)
        printf("Board generated\n");
    int mapsize = atoi(argv[1]);
    game.rungame(mapsize);
//    delete game;
    if (DEBUG > 0)
        printf("Done\n");
    return 0;
}
