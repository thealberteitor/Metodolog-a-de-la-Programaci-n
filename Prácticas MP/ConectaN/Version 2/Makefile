SRC = src
INC = include
OBJ = obj
BIN = ./bin

CXX = g++
CXXFLAGS =  -Wall -g -c -I$(INC)

all: $(BIN)/conectaN

$(BIN)/conectaN : $(OBJ)/Jugador.o $(OBJ)/Matriz.o $(OBJ)/Tablero.o $(OBJ)/ConectaFinal.o
	$(CXX) -o $(BIN)/ConectaN $(OBJ)/Tablero.o $(OBJ)/Matriz.o $(OBJ)/Jugador.o $(OBJ)/ConectaFinal.o

$(OBJ)/ConectaFinal.o : $(SRC)/ConectaFinal.cpp 
	$(CXX) $(CXXFLAGS) $(SRC)/ConectaFinal.cpp -o $(OBJ)/ConectaFinal.o

$(OBJ)/Tablero.o : $(SRC)/Tablero.cpp $(INC)/Tablero.h
	$(CXX) $(CXXFLAGS) $(SRC)/Tablero.cpp -o $(OBJ)/Tablero.o

$(OBJ)/Matriz.o : $(SRC)/Matriz.cpp  $(INC)/Matriz.h
	$(CXX) $(CXXFLAGS) $(SRC)/Matriz.cpp -o $(OBJ)/Matriz.o

$(OBJ)/Jugador.o : $(SRC)/Jugador.cpp  $(INC)/Jugador.h
	$(CXX) $(CXXFLAGS) $(SRC)/Jugador.cpp -o $(OBJ)/Jugador.o

clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

