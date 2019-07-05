#include <stdio.h>
#include <stdlib.h>
#include "mine_sweeper.h"
#include "display.h"

void print_tiles(Board* board){
	int i,j;
	printf("There are %d mines left\n", board->mine_markers);
	for (i = board->rows - 1 ; i >= 0; i--){ //Prints row numbers 
		printf("%d ", i);
		for (j = 0; j < board->cols; j++){
			printf("%c ", board->tiles[i][j]); 
			}
		printf("\n");
	}
	printf("  ");
	 for(i = 0; i < board->cols; i++){ //Prints column numbers
        printf("%d ", i);
    }
    printf("\n");
}

void print_minefield(Board* board){
	int i, j;
	for (i = board->rows - 1; i >= 0; i--){ //Prints row numbers 
		printf("%d ", i);
		for (j = 0; j < board->cols; j++){
			printf("%c ", board->minefield[i][j]); 
			}
		printf("\n");
	}
	printf("  ");
	 for(i = 0; i < board->cols; i++){ //Prints column numbers
        printf("%d ", i);
    }
    printf("\n");
}