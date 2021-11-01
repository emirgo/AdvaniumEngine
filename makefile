CC=g++
SOURCE_PATH=source
BUILD_PATH=build
EXE=$(BUILD_PATH)/advanium

advanium: $(SOURCE_PATH)/main.cpp
	$(CC) -F/Library/Frameworks -framework SDL2 -o $(EXE) $(SOURCE_PATH)/main.cpp

.PHONY: clean
clean:
	rm $(EXE)
