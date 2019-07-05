#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"
#include "load_game.h"


void read_args(int argc, char** argv, Board* board){

/*******************************************************
0 program_name
1.rows
2.cols
3.mines
4.seed

4 w/o seed
5 w/ seed
********************************************************/

	if (argc <= 3){
		printf("Not enough arguments.\n");
		printf("Usage: ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit (0);
	}
	
	else if (argc > 5){
		printf("Too many arguments.\n");
		printf("Usage: ./mine_sweeper.out num_rows num_cols num_mines [seed])\n");
		exit (0);
	}
	
	else if (argc == 4){
		board->rows = atoi(argv[1]);
		board->cols = atoi(argv[2]);
		board->mines = atoi(argv[3]);
		board->mine_markers = atoi(argv[3]);
		srand((int)time(0));
	}

	else{
		board->rows = atoi(argv[1]);
		board->cols = atoi(argv[2]);
		board->mines = atoi(argv[3]);
		board->mine_markers = atoi(argv[3]);
		srand(atoi(argv[4]));
		}
}

char** create_minefield (Board* board){
	int i,j;
	int row, col;
	int count = 0;
	char** minefield;
	int sum = 0;
	char boardValue;
	
	//Allocating space for minefield
	minefield = (char **)malloc(board->rows * sizeof(char *));
	for (i = 0; i<board->rows; i++){
		minefield[i] = (char *)malloc(board->cols * sizeof(char));
		}
		
	while(count != board->mines){
		row = rand() % board->rows;
		col = rand() % board->cols;
		if (minefield[row][col] != '*'){
			minefield[row][col] = '*';
			printf("Placing mine at %d, %d\n", row, col);
			count++;
		continue;
		}
	}

	for (i = 0; i < board->rows; i++){
		for (j = 0; j < board->cols; j++){
			sum = 0;
			if (minefield[i][j] == '*'){
			continue;}
			
			if ( ((i-1) >=  0) &&
			 ((i-1) < board->rows) &&
			 ((j-1) >= 0) &&
			 ((j-1) < board->cols) &&
			minefield[i-1][j-1] == '*' ){
			sum++;}
			
			if ( ((i-1) >=  0) &&
			 ((i-1) < board->rows) &&
			 ((j) >= 0) &&
			 ((j) < board->cols) &&
			minefield[i-1][j] == '*' ){
			sum++;}
	
			if ( ((i-1) >=  0) &&
			 ((i-1) < board->rows) &&
			 ((j+1) >= 0) &&
			 ((j+1) < board->cols) &&
			minefield[i-1][j+1] == '*' ){
			sum++;}
			
			
		 	if ( ((i) >=  0) &&
			 ((i) < board->rows) &&
			 ((j-1) >= 0) &&
			 ((j-1) < board->cols) &&
			minefield[i][j-1] == '*' ){
			sum++;}
			
			
			if ( ((i) >=  0) &&
			 ((i) < board->rows) &&
			 ((j+1) >= 0) &&
			 ((j+1) < board->cols) &&
			minefield[i][j+1] == '*' ){
			sum++;}
			
			if ( ((i+1) >=  0) &&
			 ((i+1) < board->rows) &&
			 ((j-1) >= 0) &&
			 ((j-1) < board->cols) &&
			minefield[i+1][j-1] == '*' ){
			sum++;}
			
			if ( ((i+1) >=  0) &&
			 ((i+1) < board->rows) &&
			 ((j) >= 0) &&
			 ((j) < board->cols) &&
			minefield[i+1][j] == '*' ){
			sum++;}
			
			if ( ((i+1) >=  0) &&
			 ((i+1) < board->rows) &&
			 ((j+1) >= 0) &&
			 ((j+1) < board->cols) &&
			minefield[i+1][j+1] == '*' ){
			sum++;}
			boardValue = sum + '0';
			
			minefield[i][j] = boardValue;
		}
	}
return minefield;
}

char** create_tiles (Board* board){
	int i,j;
	char** tiles;
	tiles = (char **)malloc(board->rows * sizeof(char *));
	for (i=0; i<board->rows; i++){
		tiles[i] = (char *)malloc(board->cols * sizeof(char));
		}
		
	for (i = 0; i < board->rows; i++){
		for (j = 0; j < board->cols; j++){
			tiles[i][j] = '#';
		}
	}
return tiles;
}