#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include "input_validation.h"

// we get this from the class google drive
bool isValidFormat(const int numArgsRead, const int numArgsNeed) {
  bool formatIsGood = numArgsRead == numArgsNeed;
  char character;
  do{
    scanf("%c", &character); //45  bob  \n
    if(!isspace(character)){
      formatIsGood = false;
    }
  }while(character != '\n');
  return formatIsGood;
}

int getValidInt(const char* prompt){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("%s", prompt);
    numArgsRead = scanf(" %d", &num); //45\n
  }while(!isValidFormat(numArgsRead, numArgsNeeded));

  return num;
}

bool inbetween(int val, int lowerBound, int upperBound){
  return val >= lowerBound && val <= upperBound;
}

int getValidIntInRange(int lowerBound, int upperBound){
  int num;
  const int numArgsNeeded = 1;
  int numArgsRead;
  do{
    printf("Enter a number between %d-%d: ", lowerBound, upperBound);
    numArgsRead = scanf(" %d", &num);
  }while(!(isValidFormat(numArgsRead, numArgsNeeded) &&
      inbetween(num, lowerBound, upperBound)));

  return num;
}

// check to see if the row is full
bool is_valid_row(char** board, int col) {
	if (board[0][col] == '*') {
		return true;
	}
	return false;
}

// check if the move is valid
bool is_valid_move(int num_args_read, int row, int col,
                   char** board, int col_dim) {
  return isValidFormat(num_args_read, 1) &&
  inbetween(col, 0, col_dim) &&
  is_valid_row(board, col);
}
