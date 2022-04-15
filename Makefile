CC=g++
CFLAGS= -O3 -mavx -fopenmp
DEPS = dijkstra.hpp
OBJ = main.o parallel_dijkstra.o serial_dijkstra.o generateGraph.o
EXEC = dijkstra

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) $(EXEC)
