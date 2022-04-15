/**
 * @file dijkstra.hpp
 * @author David Rohweder
 * @brief 
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// **** Global Declarations


typedef struct Graph{
    long long* graph;
    int src;
    long* serial_distance;
    long * parallel_distance;
} Graph;

#define N 40000


// **** End Global Declarations


// **** Function Prototypes


void get_walltime(double*);

void serial_Dijkstra(Graph*);

void parallel_Dijkstra(Graph*);

void generate_Graph(Graph*);

void graph_Cleanup(Graph*);

void printGraph(Graph*);

void resetDistance(Graph*);


// **** End Function Prototypes