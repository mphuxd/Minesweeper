#ifndef load_game
#define load_game
	
void read_args(int argc, char** argv, Board* board);

char** create_minefield (Board* board);

char** create_tiles (Board* board);

#endif