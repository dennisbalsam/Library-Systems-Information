CC = clang++
FLAGS = -std=c++11
SRC = ../src
BIN = bin

$(BIN)/BookInformationTest : BookInformationTest.cpp ../BookInformation.cpp
	$(CC) $(FLAGS) $^ -o $@

clean:
	rm $(BIN)/*