CXX=g++
CC=gcc
CFLAGS=-O3 -Wall -g -std=gnu99 -msse4.2
CXXFLAGS=-O0 -Wall -g -std=gnu++11 -msse4.2 
LDLIBS=
BIN=$(shell basename `pwd`)
all: $(BIN)

$(BIN):	$(BIN).cc
	$(CXX) $(CXXFLAGS)  $^ -o $@ $(LDLIBS)

clean:
	$(RM) $(BIN)

