CC=g++
BUILD_PATH=build
EXE=$(BUILD_PATH)/advanium

advanium: main.cpp
	$(CC) -F/Library/Frameworks -framework SDL2 -o $(EXE) main.cpp

.PHONY: clean
clean:
	rm $(EXE)
