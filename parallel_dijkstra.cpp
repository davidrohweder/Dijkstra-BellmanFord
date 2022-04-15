/**
 * @file serial_dijkstra.cpp
 * @author David Rohweder
 * @brief Dijkstras algorithm parallel implementation
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// **** Includes

#include <climits>
#include <omp.h>
#include "dijkstra.hpp"

// **** End Includes


// **** Function Region


/*
    Naive, Serial Implementation of Dijksta's Algorithm... O(|V|) runtime and O(|V|*|E|) storage 
*/
void parallel_Dijkstra(Graph* graph, int P)
{
    bool* visited = new bool[N];

    omp_set_num_threads(P);

    #pragma omp parallel for num_threads(P)
    for(int i = 0; i < N; i++) {
        graph->parallel_distance[i] = INT_MAX;
        visited[i] = false;    
    } // initalize all elements in distance vector to "infinity"

    graph->parallel_distance[graph->src] = 0; // source vertex has distance 0               

    #pragma omp parallel for num_threads(P) schedule(auto)
    for(int i = 0; i < N; i++) {
        int s = smallest_Distance(graph->parallel_distance,visited); 
        visited[s] = true;

        for(int j = 0; j < N; j++) {
            if(!visited[j] && graph->graph[s * N + j] && graph->parallel_distance[s] != INT_MAX && graph->parallel_distance[s] + graph->graph[s * N + j] < graph->parallel_distance[j]) {
                graph->parallel_distance[j]= graph->parallel_distance[s] + graph->graph[s * N + j];
            }
        } // updating the distance of neighbouring vertex
    }

    // Cleanup
    delete[] visited;

}