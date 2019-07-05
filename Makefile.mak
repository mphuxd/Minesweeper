mine_sweeper.out: mine_sweeper.o main.o load_game.o actions.o display.o end_game.o
	gcc main.o mine_sweeper.o load_game.o actions.o display.o end_game.o -o mine_sweeper.out

main.o: main.c
	gcc -c main.c 

mine_sweeper.o: mine_sweeper.c
	gcc -c mine_sweeper.c

load_game.o: load_game.c
	gcc -c load_game.c

actions.o: actions.c
	gcc -c actions.c

display.o: display.c
	gcc -c display.c
	
end_game.o: end_game.c
	gcc -c end_game.c
	
clean:
	rm *o mine_sweeper.out