CC=g++
SOURCE_PATH=source
INCLUDE_PATH=-Iinclude
BUILD_PATH=build
EXE=$(BUILD_PATH)/advanium

advanium: $(SOURCE_PATH)/main.cpp
	$(CC) -F/Library/Frameworks -framework SDL2 -o $(EXE) $(INCLUDE_PATH) $(SOURCE_PATH)/main.cpp

.PHONY: clean
clean:
	rm $(EXE)

run:
	./build/advanium
