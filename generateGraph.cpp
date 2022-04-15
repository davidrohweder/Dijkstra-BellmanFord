/**
 * @file generateGraph.cpp
 * @author David Rohweder
 * @brief Generates adjacency graph for dijkstra algorithm
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// **** Includes


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dijkstra.hpp"


// **** End Includes


/*
    generates graph because HPC course needs big data graph ;)
*/
void generate_Graph(Graph* graph_setup) {

    // Setup 
    int* connected = new int[N * N];
    srand ( time(NULL) );
    
    // Initialize
    graph_setup->src = 0; 
    graph_setup->graph = new int[N * N];
    graph_setup->serial_distance = new int[N];
    graph_setup->parallel_distance = new int[N];

    // Initialize Graph

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){
            graph_setup->graph[i * N + j] = 0;
        }
    }

    // Fill Graph
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++){

            int chance1 = rand() % 2;
            int chance2 = rand() % 10; // can switch between the amount of edges desired

            if (chance1 == 0 && connected[i * N + j] == 0 && !(j==i)) {
                int randNum = rand() % 10;
                graph_setup->graph[i * N + j] = randNum;
                graph_setup->graph[j * N + i] = randNum;
                connected[i * N + j] = 1;
            } // reduce lilkey hood to have connections . also do not change connection if exists or create one if self

        }
    }

    // Cleanup
    delete[] connected;

}


void printGraph(Graph* graph) {
   for (int i = 0; i < N; i++) {
        printf("{");
        for (int j = 0; j < N; j++){
            if (j == N -1) {
                printf("%d", graph->graph[i * N + j]);
            } else {
                printf("%d, ", graph->graph[i * N + j]);
            }
        }
        printf("}\n");
    }
}


void graph_Cleanup(Graph* graph){
    delete[] graph->graph;
    delete[] graph->serial_distance;
    delete[] graph->parallel_distance;
    delete[] graph;
}