#ifndef BOARD_H
  #define BOARD_H

	void fetch_board_parameters_from_command_line(int argc, char** argv,
	  																						char* player_pieces, int length_player_pieces,
	  																					  int* row_dim, int* col_dim, int* pieces_win);
	char** create_board(int row_dim, int col_dim);
  void display_board (char** board, int row_dim, int col_dim);
  void destroy_board(char** board, int row_dim, int col_dim);

#endif
