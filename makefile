CC=g++
EXE=advanium

setup: main.cpp
	$(CC) -F/Library/Frameworks -framework SDL2 -o $(EXE) main.cpp

.PHONY: clean
clean:
	rm $(EXE)
