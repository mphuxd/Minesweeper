#ifndef mine_sweeper_h
#define mine_sweeper_h

typedef struct Board_struct{
	int rows;
	int cols;
	int mines;
	int mine_markers;
	int seed; //Interacts with rand to produce random numbers. If no input, sync with time
	char** tiles; //Holds status of tiles. Tiles should be linked to board   
	char** minefield;
}Board;



int action(Board* board, int* row, int* col);

void play_game(Board* board);

	
#endif