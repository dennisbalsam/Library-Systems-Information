CC = clang++
FLAGS = -std=c++11
SRC = ../src
COMPILE = $(CC) $(FLAGS) $^ -o $@
BIN = bin

$(BIN)/BookInformationTest : BookInformationTest.cpp ../BookInformation.cpp
	$(COMPILE)

$(BIN)/BorrowerInformationTest : BorrowerInformationTest.cpp
	$(COMPILE)

$(BIN)/dataImportTest : dataImportTest.cpp ../LibraryInventory.cpp ../BookInformation.cpp
	$(COMPILE)

$(BIN)/dateTest : dateTest.cpp
	$(COMPILE)

$(BIN)/LibraryInventoryTest : LibraryInventoryTest.cpp ../LibraryInventory.cpp ../BookInformation.cpp
	$(COMPILE)

clean:
	rm $(BIN)/*