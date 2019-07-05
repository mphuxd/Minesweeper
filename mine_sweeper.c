#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"
#include "display.h"
#include "load_game.h"
#include "actions.h"
#include "end_game.h"
/*
int valid_play(Board* board, int* row, int* col){
	int play_row = 0;
	int play_col = 0;
	printf("Enter row a row between 0-%d and a column between 0-%d: ", board->rows - 1, board->cols - 1);
	scanf("%d %d", &play_row, &play_col);
	check_boundaries(board, play_row, play_col);
	valid_tile(board, play_row, play_col);
	while(check_boundaries(board, play_row, play_col) == 0 && valid_tile(board, play_row, play_col) == 0 ){
	printf("Enter row a row between 0-%d and a column between 0-%d: ", board->rows - 1, board->cols - 1);
	scanf("%d %d", &play_row, &play_col);
	check_boundaries(board, play_row, play_col);
	valid_tile(board, play_row, play_col);
	continue;
	}
*row = play_row;
*col = play_col;
return 1;
}
*/
int check_boundaries(Board* board, int row, int col){
	if(row >= board->rows || row < 0 ||  col >= board->cols || col < 0 ){
	return 0;}
	else{
	return 1;
	}
}


void play_game(Board* board){
	int row = 0; 
	int col = 0;
	int selection = 0;
	int win_status = 0;
	while(win_status != 1){ 
	selection = action(board, &row, &col);
	if (selection == 0){
	reveal_tile(board, row, col);
	}
	else if (selection == 1){
	question_tile(board, row, col);}
	else if (selection == 2){
	mark_tile(board, row, col);}
	else if (selection == 3 || selection == 11 || selection == 21){
	continue;
	}
	else if (selection == 10){
	unquestion_tile(board, row, col);
	}
	else if (selection == 20){
	unMark_tile(board, row, col);
	}
	else{
	continue;}
	win_status = win_check(board);
	print_tiles(board);
	}
}



int action(Board* board, int* row, int* col){
	int action = 0;
	int play_row;
	int play_col;
	int invalid = 0;
	
	while(invalid == 0){
	printf("Enter row a row between 0-%d and a column between 0-%d: ", board->rows - 1, board->cols - 1);
	scanf("%d %d", &play_row, &play_col);
	if(play_row >= board->rows || play_row < 0 ||  play_col >= board->cols || play_col < 0 ){
	continue;}
	else if(board->tiles[play_row][play_col] != '#' && board->tiles[play_row][play_col] != '!' && board->tiles[play_row][play_col] != '?' ){
	printf("This tile is already revealed.\n");
	continue;}
	else{
	break;}
	}
	
	if (board->tiles[play_row][play_col] == '#'){
	printf("Enter Action\n");
	printf("0. Reveal\n");
	printf("1. Question\n");
	printf("2. Mark\n");
	printf("3. Cancel\n");
	printf("Action: ");
	scanf("%d", &action);}
	if(action < 0 || action > 3){
	play_game(board);}
	else if (board->tiles[play_row][play_col] == '?'){
	printf("Enter Action\n");
	printf("0. UnQuestion\n");
	printf("1. Cancel\n");
	printf("Action: ");
	scanf("%d", &action);
	if(action < 0 || action > 3){
	play_game(board);}
	action = action + 10;
	}

	else if (board->tiles[play_row][play_col] == '!'){
	printf("Enter Action\n");
	printf("0. UnMark\n");
	printf("1. Cancel\n");
	printf("Action: ");
	scanf("%d", &action);
	if(action < 0 || action > 3){
	play_game(board);}
	action = action + 20;
	}

	*row = play_row;
	*col = play_col;
return action;
}	




