#include <stdlib.h>
#include <stdio.h>
#include "board.h"

// get parameters for board from User
void fetch_board_parameters_from_command_line(int argc, char** argv,
  																						char* player_pieces, int length_player_pieces,
  																					  int* row_dim, int* col_dim, int* pieces_win) {
	// check the number of arguments given
  if (argc == 4) { // correct number of args passed to play
    int num_args_read;
    char should_be_blank;		// make sure the space is blank

		// get the number of rows
    num_args_read = sscanf(argv[1], "%d %c", row_dim, &should_be_blank);

    if (num_args_read == 1) {		// check to make sure the row num is correct
      if (!(*row_dim > 0)) {		// if less or equal to 0 then exit
        printf("Error the dimensions of the board must be greater 0.\n");
        printf("Ending program\n");
        exit(0);
      }
    } else {		// end if not an integer
      printf("Error! The dimensions must be a integer number\n");
      printf("Ending program\n");
      exit(0);
    }

		// get the number of cols
		num_args_read = sscanf(argv[2], "%d %c", col_dim, &should_be_blank);

    if (num_args_read == 1) {		// check to make sure the col num is correct
      if (!(*col_dim > 0)) {		// if less or equal to 0 then exit
        printf("Error the dimensions of the board must be greater 0.\n");
        printf("Ending program\n");
        exit(0);
      }
    } else {		// end if not an integer
      printf("Error! The dimensions must be a integer number\n");
      printf("Ending program\n");
      exit(0);
    }

		// get the number of pieces to win
    num_args_read = sscanf(argv[3], "%d %c", pieces_win, &should_be_blank);
		if (num_args_read == 1) {		// check to make sure the piece num is correct
			if (!(*pieces_win > 0)) { 		// if less than 0 exit
				printf("Error the dimensions of the board must be greater 0.\n");
				printf("Ending program\n");
				exit(0);
			}
		} else {		// must be an integer
			printf("Error! The dimensions must be a integer number\n");
			printf("Ending program\n");
			exit(0);
		}
  } else if (argc < 4) {	// if arguments < 4 not enough
		printf("Not enough arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	} else {		// if arguments > 4 too many
		printf("Too many arguments entered\n");
		printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
		exit(0);
	}
}

// this function will create our game board
char** create_board(int row_dim, int col_dim){
  // making the correct size for our board dimension
  char** board = calloc(row_dim, sizeof(*board));
  // in this loop we will create the board
  for (int i = 0; i < row_dim; ++i) {
    board[i]= calloc(col_dim, sizeof(*board[i]));
    for (int j = 0; j < col_dim; ++j) {
      board[i][j] = '*';
    }
  }
  return board;

}

// this function will display the board for the user
void display_board (char** board, int row_dim, int col_dim) {

	int row = row_dim;
	int col = col_dim;
	// this loop will display row headers
	for (int i = 0; i < row; ++i) {
		if(i > 9) {		// row header
			printf("%2d ", row - 1 - i);
		} else {
			printf("%d ", row - 1 - i);
		}
		for (int j = 0; j < col; ++j) {
			if (col > 9) {
				printf("%2c ", board[i][j]);
			} else {
				printf("%c ", board[i][j]);
			}
		}
		printf("\n");
	}

	printf(" ");	// space before column headers

	if (col_dim > 9) {
			printf(" ");
			for (int i = 0; i < col; i++) {
					if (i > 9) {
							printf(" %2d", i);
					} else {
							printf("  %d", i);
					}
			}
	} else {
			for (int i = 0; i < col; i++)  {
					printf("%2d", i);
			}
	}

	printf("\n");

}


// this function destroys the board
void destroy_board(char** board, int row_dim, int col_dim) {
  for (int i = 0; i < row_dim; ++i) {		// free board for num rows
    free(board[i]);
  }
  free(board);
}
