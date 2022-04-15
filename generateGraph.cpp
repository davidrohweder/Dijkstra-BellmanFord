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
    return;
    // Initialize
    graph_setup->src = 0; 
    return;
    graph_setup->graph = new int[N * N];
    graph_setup->serial_distance = new int[N];
    graph_setup->parallel_distance = new int[N];
    return;



    // Fill Graph
    for (int i = 0; i < N; i++) {

        for (int j = 0; j < N; j++){

            int chance1 = rand() % 2;
            int chance2 = rand() % 10;

            if (chance1 == 0 && chance2 == 0 && connected[i * N + j] == 0) {
                int randNum = rand() % 10;
                graph_setup->graph[i * N + j] = randNum;
                graph_setup->graph[j * N + i] = randNum;
                connected[i * N + j] = 1;
            } // reduce lilkey hood to have connections . also do not change connection if exists
            
        }
    }

    // Cleanup
    delete[] connected;

}

void graph_Cleanup(Graph* graph){
    delete[] graph->graph;
    delete[] graph->serial_distance;
    delete[] graph->parallel_distance;
}