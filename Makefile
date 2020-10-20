CC=g++
BIN=main
ARG=-std=c++11 -g

All: $(BIN)

$(BIN): main.cpp Plot.o Point.o
	$(CC) $(ARG) main.cpp  Plot.o Point.o -o $(BIN)

Plot.o: Plot.cpp Plot.hpp
	$(CC) $(ARG) -c Plot.cpp

Point.o: Point.cpp Point.hpp
	$(CC) $(ARG) -c Point.cpp

clean:
	rm -f *.o $(BIN)

