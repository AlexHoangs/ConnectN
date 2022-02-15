/* main.c
Angelina Lim and Alexander Hoang
ECS36A Homework 5.2 Connect N

This program will create a game called Connect N
*/

#include <stdio.h>
#include "game.h"

int main(int argc, char** argv) {
  // initilaize variables
  char** board;
  char* player_pieces;
  int cur_player_turn;
  int row_dim, col_dim;
	int pieces_win;

	setup_game (argc, argv, &board, &row_dim, &col_dim, &pieces_win,
	  					&player_pieces, &cur_player_turn);
	play_game(board, row_dim, col_dim, pieces_win,
						player_pieces, cur_player_turn);
  cleanup_game(board, row_dim, col_dim, player_pieces);
  return 0;
}
