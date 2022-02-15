#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "game.h"
#include "board.h"
#include "game_over.h"
#include "input_validation.h"

// set up the connect N game
void setup_game (int argc, char** argv, char*** board, int* row_dim, int* col_dim,
  							 int* pieces_win, char** player_pieces, int* cur_player_turn) {
  *player_pieces = calloc(2, sizeof(*player_pieces));   // assign players the pieces for the game
  (*player_pieces)[0] = 'X';  // player1 will X
  (*player_pieces)[1] = 'O';  // player2 will be O
	// get the board parameters from user
	fetch_board_parameters_from_command_line(argc, argv,
	  																			*player_pieces, 2, row_dim,
																					col_dim, pieces_win);		// in board.c
	// create the board
  *board = create_board(*row_dim, *col_dim);		// in board.c
  *cur_player_turn = 0;  // player 1 always goes first
}

// start the game play
void play_game(char** board, int row_dim, int col_dim, int pieces_win,
               char* player_pieces, int player_turn) {
  while(true) {
    player_take_turn(board, row_dim, col_dim, player_pieces[player_turn], player_turn + 1);
		if(is_game_over(board, row_dim, col_dim, pieces_win)) {		// game_over.c
			break;
		}
		change_turn(&player_turn);
  }
  declare_results_of_game(board, row_dim, col_dim, pieces_win, player_turn + 1);
}

// have the players take their turn
void player_take_turn(char** board, int row_dim, int col_dim, char player_piece,
                      int player_id) {
  int row, col;
  display_board (board, row_dim, col_dim);	// board.c
	get_move_from_player(&row, &col,
	                     board, col_dim);
  make_move(board, row_dim, col, player_piece);
}

// get the player move
void get_move_from_player(int* row, int* col,
                          char** board, int col_dim) {
  int num_args_read;
  // have the player move until their moves aren't valid
  do {
    printf("Enter a column between 0 and %d to play in: ", col_dim - 1);
    num_args_read = scanf("%d", col);
  } while (!is_valid_move(num_args_read, *row, *col,
	                   			board, col_dim));		// input_validation.c
}

// make the move of the player
void make_move(char** board, int row_dim, int col, char piece) {
	for(int i = row_dim - 1; i >= 0; --i) {
		if(board[i][col] == '*') {
			board[i][col] = piece;
			break;
		}
	}
}

// change player turn
void change_turn (int*turn) {
  // 0 means its player 1's turn
  // 1 means its player 2's turn
  *turn = (*turn + 1) % 2;
}

// show results of game
void declare_results_of_game(char** board, int row_dim, int col_dim,
														 int pieces_win, int player_turn) {
	display_board (board, row_dim, col_dim); 	// board.c
	if (someone_won(board, row_dim, col_dim, pieces_win)) {		// game_over.c
    printf("Player %d Won!\n", player_turn);
  } else {
    printf("Tie game!\n");
  }
}

// clean up the game board
void cleanup_game(char** board, int row_dim, int col_dim, char* player_pieces) {
  destroy_board(board, row_dim, col_dim);		// board.c
  free(player_pieces);
}
