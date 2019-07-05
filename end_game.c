#include <stdio.h>
#include <stdlib.h>
#include "mine_sweeper.h"
#include "display.h"
#include "end_game.h"

int win_check(Board* board){
	int i, j;
	int minesMarked = 0;

	for(i = 0; i < board->rows; i++){
		for(j = 0; j < board->cols; j++){
			if ((board->tiles[i][j] == '#') || (board->tiles[i][j] == '?')){
			return 0;}
		}
	}
	
	
	for(i = 0; i < board->rows; i++){
		for(j = 0; j < board->cols; j++){
			if (board->tiles[i][j] == '!' &&
				board->minefield[i][j] == '*'){
				minesMarked++;
				}
		}
	}
	
	if(board->mine_markers == 0 && board->mines == minesMarked){
	game_won(board);
	}
	
return 0;
}


void game_won(Board* board){
	print_minefield(board);
	printf("You Won!!\n");
	destroy_boards(board);
	exit(0);
}

void game_lost(Board* board){
	print_minefield(board);
	printf("You Lost :(\n");
	destroy_boards(board);
	exit(0);
}

void destroy_boards(Board* board){
	int i, j;
	for(i = 0; i < board->rows; i++){
		free(board->tiles[i]);
	}
	free(board->tiles);
	
	for(i = 0; i < board->rows; i++){
		free(board->minefield[i]);
	}
	free(board->minefield);
}
