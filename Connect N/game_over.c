#include <stdbool.h>
#include <stdlib.h>
#include "game_over.h"

// will check to see if the game is over
// will either be a tie or that someone won
bool is_game_over(char** board, int row_dim, int col_dim, int pieces_win) {
  return someone_won(board, row_dim, col_dim, pieces_win) || tie(board, row_dim, col_dim);
}

// will check to see if someone won
bool someone_won(char** board, int row_dim, int col_dim, int pieces_win) {
  return won_horizontally(board, row_dim, col_dim, pieces_win) ||
         won_vertically(board, row_dim, col_dim, pieces_win) ||
         won_diagonally(board, row_dim, col_dim, pieces_win);
}

// will check if the user won horizontally
bool won_horizontally(char** board, int row_dim, int col_dim, int pieces_win) {
	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < row_dim; ++i) {
		for(int j = 0; j < col_dim; ++j) {
			if (board[i][j] == 'X') {
				++count1;
			} else {
				count1 = 0;
			}
			if (board[i][j] == 'O') {
				++count2;
			} else {
				count2 = 0;
			}
			if (count1 >= pieces_win || count2 >= pieces_win) {
				return true;
			}
		}
		count1 = 0;
		count2 = 0;
}
	return false;
}

// will check if the user won vertically
bool won_vertically(char** board, int row_dim, int col_dim, int pieces_win) {
	int countx = 0;
	int counto = 0;

	for (int i = 0; i < col_dim; i++) {
		for (int j = 0; j < row_dim; j++) {
			if(board[j][i] == 'X') {
				countx++;
			} else {
				countx = 0;
			}
			if(board[j][i] == 'O') {
				counto++;
			} else {
				counto = 0;
			}
			if (countx >= pieces_win || counto >= pieces_win) {
				return true;
			}
		}
		countx = 0;
		counto = 0;
	}
	return false;
}

// will call the functions to check if user won diagonally
bool won_diagonally(char** board, int row_dim, int col_dim, int pieces_win) {
  return won_right_diagonally(board, row_dim, col_dim, pieces_win) ||
  won_left_diagonally(board, row_dim, col_dim, pieces_win);
}

// check if player won right diagonally
bool won_right_diagonally(char** board, int row_dim, int col_dim, int pieces_win) {
  /*
    X
      X
        X
  */
	int countx = 0;		// for counting pieces win
	int counto = 0;
	int sub = 0;
	// check if the row is winning diagonally
	// if the top right corner is an * then false
	// else then see if the pieces are in a left diagonal
	// use count to check if they are all the same
	for (int i = col_dim; i >= 0; i--) {
		for (int j = 0; j < row_dim; j++) {
			if (board[j][i - sub] == 'X') {
				countx++;
			} else {
				countx = 0;
			}
			if (board[j][i - sub] == 'O') {
				counto++;
			} else {
				counto = 0;
			}
			sub++;
			if (countx >= pieces_win || counto >= pieces_win) {
				return true;
			}
		}
		countx = 0;
		counto = 0;
		sub = 0;
	}
	return false;
}

// if the player wins left diagonally
bool won_left_diagonally(char** board, int row_dim, int col_dim, int pieces_win) {
  /*
        X
      X
    X
  */
	int countx = 0;		// for counting pieces win
	int counto = 0;
	int add = 0;
	// check if the row is winning diagonally
	// if the top right corner is an * then false
	// else then see if the pieces are in a left diagonal
	// use count to check if they are all the same
	for (int i = 0; i < col_dim; i++) {
		for (int j = 0; j < row_dim; j++) {
			if (board[j][i + add] == 'X') {
				countx++;
			} else {
				countx = 0;
			}
			if (board[j][i + add] == 'O') {
				counto++;
			} else {
				counto = 0;
			}
			add++;
			if (countx >= pieces_win || counto >= pieces_win) {
				return true;
			}
		}
		countx = 0;
		counto = 0;
		add = 0;
	}
	return false;
}

// this will be if the game is a tie
bool tie(char** board, int row_dim, int col_dim) {
  // before calling this function first check if a win has happened
	int piececount = 0;
  for (int i = 0; i < row_dim; ++i) {
    for (int j = 0; j < col_dim; ++j) {
			if (board[i][j] != '*') {
				piececount++;
      }
    }
  }
	if (piececount == (row_dim*col_dim)) {
		return true;
	}
  return false;
}
