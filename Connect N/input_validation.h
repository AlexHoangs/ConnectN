#ifndef INPUT_VALIDATION_H
  #define INPUT_VALIDATION_H
	#include <stdbool.h>

  bool isValidFormat(const int numArgsRead, const int numArgsNeed);
  bool inbetween(int val, int lowerBound, int upperBound);
	bool is_valid_move(int num_args_read, int row, int col,
	                   char** board, int col_dim);;

#endif
