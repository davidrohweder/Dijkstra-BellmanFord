/**
 * @file serial_dijkstra.cpp
 * @author David Rohweder
 * @brief Dijkstras algorithm serial implementation
 * @version 0.1
 * @date 2022-04-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// **** Includes

#include <climits>
#include "dijkstra.hpp"

// **** End Includes


// **** Function Region


/*
    Naive, Serial Implementation of Dijksta's Algorithm... O(|V|) runtime and O(|V|*|E|) storage 
*/
void serial_Dijkstra(Graph* graph)
{
    long* visited = new long[N];
    
    for(int i = 0; i < N; i++) {
        graph->serial_distance[i] = INT_MAX;
        visited[i] = 0;    
    } // initalize all elements in distance vector to "infinity"
    
    graph->serial_distance[graph->src] = 0; // source vertex has distance 0               
    
    for(int i = 0; i < N; i++) {
        int s, min;
        for (int z = 0; i < N; i++) {
            if(visited[z] == 0 && graph->serial_distance[z] <= min) {
            min = graph->serial_distance[z];
            s = z;
            }
        } // find vertex with shortest minimum distance
        
        visited[s] = 1;

        for(int j = 0; j < N; j++) {
            if(visited[j] == 1 && graph->graph[s * N + j] && graph->serial_distance[s] != INT_MAX && graph->serial_distance[s] + graph->graph[s * N + j] < graph->serial_distance[j]) {
                graph->serial_distance[j]= graph->serial_distance[s] + graph->graph[s * N + j];
            }
        } // updating the distance of neighbouring vertex
    }

    // Cleanup
    delete[] visited;

}