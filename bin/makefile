SRC=../src
NAME=tetris

all: test

$(NAME).exec: $(SRC)/$(NAME).cpp
	g++ $(SRC)/$(NAME).cpp -o $(NAME).exec -D_THREAD_SAFE -I/usr/local/include/SDL2 -L/usr/local/lib -lSDL2_image -lSDL2 -lSDL2_ttf

test: $(NAME).exec
	./$(NAME).exec

clean:
	rm *.exec

.PHONY: clean all test