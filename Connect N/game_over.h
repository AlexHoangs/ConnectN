#ifndef GAME_OVER_H
  #define GAME_OVER_H
  #include <stdbool.h>

  bool is_game_over(char** board, int row_dim, int col_dim, int pieces_win);
  bool someone_won(char** board, int row_dim, int col_dim, int pieces_win);
  bool won_horizontally(char** board, int row_dim, int col_dim, int pieces_win);
  bool won_vertically(char** board, int row_dim, int col_dim, int pieces_win);
  bool won_diagonally(char** board, int row_dim, int col_dim, int pieces_win);
  bool won_right_diagonally(char** board, int row_dim, int col_dim, int pieces_win);
	bool won_left_diagonally(char** board, int row_dim, int col_dim, int pieces_win);
  bool tie(char** board, int row_dim, int col_dim);
#endif
