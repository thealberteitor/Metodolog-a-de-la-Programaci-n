#!/bin/bash

AR= ar
CXX= g++
LDFLAGS= -L
LDLIBS= -lformas
CXXFLAGS= -Wall -g -I $(INC)
INC= include
LIBS= -L./lib -lformas
INCLUDE= include
BIN= bin
LIB= lib
SRC= src
OBJ= obj


all: $(BIN)/central $(BIN)/area $(BIN)/longitud $(BIN)/delimitador clean

$(OBJ)/area.o : $(INCLUDE)/circulo.h $(SRC)/area.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/area.o $(SRC)/area.cpp
$(OBJ)/punto.o : $(INCLUDE)/punto.h $(SRC)/punto.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/punto.o $(SRC)/punto.cpp
$(OBJ)/circulo.o : $(INCLUDE)/punto.h $(INCLUDE)/circulo.h $(SRC)/circulo.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/circulo.o $(SRC)/circulo.cpp
$(OBJ)/central.o : $(INCLUDE)/punto.h $(INCLUDE)/circulo.h $(SRC)/central.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/central.o $(SRC)/central.cpp
$(BIN)/longitud: $(OBJ)/longitud.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/longitud $(OBJ)/longitud.o $(LIBS)
$(OBJ)/longitud.o: $(SRC)/longitud.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/longitud.o $(SRC)/longitud.cpp
$(BIN)/delimitador: $(OBJ)/delimitador.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/delimitador $(OBJ)/delimitador.o $(LIBS)
$(OBJ)/delimitador.o: $(SRC)/delimitador.cpp
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/delimitador.o $(SRC)/delimitador.cpp
$(OBJ)/rectangulo.o: $(SRC)/rectangulo.cpp $(INCLUDE)/rectangulo.h
	$(CXX) -c $(CXXFLAGS) -o $(OBJ)/rectangulo.o $(SRC)/rectangulo.cpp
$(BIN)/central : $(OBJ)/central.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/central $(OBJ)/central.o $(LIBS)
$(BIN)/area : $(OBJ)/area.o $(LIB)/libformas.a
	$(CXX) -o $(BIN)/area $(OBJ)/area.o $(LIBS)
$(LIB)/libformas.a : $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o
	$(AR) rvs $(LIB)/libformas.a $(OBJ)/punto.o $(OBJ)/circulo.o $(OBJ)/rectangulo.o 

clean:
	echo "Limpiando ..."
	rm $(OBJ)/*.o $(LIB)/lib*.a

mrproper: clean
	rm $(BIN)/central






