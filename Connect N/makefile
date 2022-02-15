connectn.out: board.o game_over.o game.o input_validation.o main.o
	gcc -g -Wall -Werror -o connectn.out board.o game_over.o game.o input_validation.o main.o

board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c

game_over.o: game_over.c game_over.h
	gcc -g -Wall -Werror -c game_over.c

game.o: game.c game.h game_over.h board.h input_validation.h
	gcc -g -Wall -Werror -c game.c

input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

main.o: main.c game.h
	gcc -g -Wall -Werror -c main.c

clean:
	rm -f *.o *.out
