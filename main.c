#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mine_sweeper.h"
#include "load_game.h"
#include "actions.h"
#include "end_game.h"
#include "display.h"


int main(int argc, char** argv){
	Board* board = NULL;
	board = (Board*)malloc(sizeof(Board));
	read_args(argc, argv, board);
	board->minefield = create_minefield(board);
	board->tiles = create_tiles(board);
	print_tiles(board);
	//print_minefield(board);
	play_game(board);
	
return 0;
}
	
	
	
	
