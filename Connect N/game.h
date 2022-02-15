
#ifndef GAME_H
  #define GAME_H

	void setup_game(int argc, char** argv, char*** board, int* row_dim, int* col_dim,
	  						int* pieces_win, char** player_pieces, int* cur_player_turn);
	void play_game(char** board, int row_dim, int col_dim, int pieces_win,
							 char* player_pieces, int player_turn);
	void player_take_turn(char** board, int row_dim, int col_dim, char player_piece,
						 	          int player_id);
	void get_move_from_player(int* row, int* col,
												    char** board, int col_dim);
  void make_move(char** board, int row_dim, int col, char piece);
  void change_turn(int* turn);
	void declare_results_of_game(char** board, int row_dim, int col_dim,
															 int pieces_win, int player_turn);
  void cleanup_game(char** board, int row_dim, int col_dim, char* player_pieces);

#endif
