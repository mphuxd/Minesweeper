# Minesweeper
Console-based Minesweeper game

This was the final project assigned for ECS30 - Programming and Problem Solving in C

The game of minesweeper works as follows:
1. There is a rectangular grid of tiles
2. Hidden under some of the tiles are mines
3. Your goal is to mark all the tiles that contain mines and uncover all the tiles
that don't contain mines
4. If you uncover a tile that contains a mine you lose the game
5. If you uncover a tile that doesn't contain a mine, it tells you how many mines
are hidden in the eight surrounding squares
6. If all the mines are marked and all the safe tiles are uncovered, you have won.

# Usage
To run the program, first travel to the file directory in the console
Type: ./mine_sweeper.out num_rows num_cols num_mines [seed]
If the seed is not specified, it will be randomly generated.

# Playing
Follow the instructions given
