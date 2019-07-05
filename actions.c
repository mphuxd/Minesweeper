#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"
#include "end_game.h"
#include "actions.h"


void question_tile(Board* board, int row, int col){
	board->tiles[row][col] = '?';
}

void unquestion_tile(Board* board, int row, int col){
	board->tiles[row][col] = '#';
}

void mark_tile(Board* board, int row, int col){
	board->tiles[row][col] = '!';
	board->mine_markers--;
}

void unMark_tile(Board* board, int row, int col){
	board->tiles[row][col] = '#';
	board->mine_markers++;
}

void reveal_tile(Board* board, int row, int col){
	if(board->minefield[row][col] == '*'){ //if reveal selection == '*' then game is lost
	game_lost(board);}
	
	else if (board->minefield[row][col] != '0'){ //if reveal selection is not reveal to 0, then just reveal the tile. this excludes '*' since it was checked before
	board->tiles[row][col] = board->minefield[row][col];}
	
	else if (board->minefield[row][col] == '0'){ //if reveal selection is equal to 0, then the tile will be "revealed" to 0 and recursion is called to reveal other tiles which are also 0
	board->tiles[row][col] = '0';
	recursion(board, row, col);
	}
}

void recursion(Board* board, int row, int col){
	reveal1(board,row+1, col-1);
	reveal2(board,row+1, col);
	reveal3(board,row+1, col+1);
	reveal4(board,row, col-1);
	reveal5(board,row, col+1);
	reveal6(board,row-1, col-1);
	reveal7(board,row-1, col);
	reveal8(board,row-1, col+1);
}


void reveal1(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	board->tiles[row][col] = '0';
	recursion(board,row,col);}
	//reveal1(board, row+1, col-1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
	board->tiles[row][col] = board->minefield[row][col];
	}
}
	
void reveal2(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	 board->tiles[row][col] = '0';
	 recursion(board,row,col);}
	//reveal2(board, row+1, col);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}
	
void reveal3(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	 board->tiles[row][col] = '0';
	 recursion(board,row,col);}
	//reveal3(board, row+1, col+1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}
	
void reveal4(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	 board->tiles[row][col] = '0';
	 recursion(board,row,col);}
	//reveal4(board, row, col-1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}

void reveal5(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	 board->tiles[row][col] = '0';
	 recursion(board,row,col);}
	//reveal5(board, row, col+1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}

void reveal6(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	board->tiles[row][col] = '0';
	recursion(board,row,col);}
	//reveal6(board, row-1, col-1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}

void reveal7(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	board->tiles[row][col] = '0';
	recursion(board,row,col);}
	//reveal7(board, row-1, col);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
	
}

void reveal8(Board* board, int row, int col){
	int valid = check_boundaries(board, row, col);
	if(valid == 1 && board->minefield[row][col] == '0' && board->tiles[row][col] == '#'){
	 board->tiles[row][col] = '0';
	recursion(board,row,col);}
	//reveal8(board, row-1, col+1);}
	else if(valid == 1 && board->minefield[row][col] != '*' && board->tiles[row][col] == '#'){
		board->tiles[row][col] = board->minefield[row][col];
	}
}