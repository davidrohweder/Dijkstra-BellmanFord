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


int smallest_Distance(int distance[], bool visited[])
{
    int minimum = INT_MAX , idx;

    for(int i = 0; i < N; i++) 
    {
        if(visited[i] == false && distance[i] <= minimum)      
        {
            minimum = distance[i];
            idx = i;
        }
    }
    return idx;
}


/*
    Naive, Serial Implementation of Dijksta's Algorithm... O(|V|) runtime and O(|V|*|E|) storage 
*/
void serial_Dijkstra(Graph* graph)
{
    bool* visited = new bool[N];

    for(int i = 0; i < N; i++) {
        graph->serial_distance[i] = INT_MAX;
        visited[i] = false;    
    } // initalize all elements in distance vector to "infinity"

    graph->serial_distance[graph->src] = 0; // source vertex has distance 0               

    for(int i = 0; i < N; i++) {
        int s = smallest_Distance(graph->serial_distance,visited); 
        visited[s]=true;

        for(int j = 0; j < N; j++) {
            if(!visited[j] && graph->graph[s * N + j] && graph->serial_distance[s] != INT_MAX && graph->serial_distance[s] + graph->graph[s * N + j] < graph->serial_distance[j]) {
                graph->serial_distance[j]= graph->serial_distance[s] + graph->graph[s * N + j];
            }
        } // updating the distance of neighbouring vertex
    }

    // Cleanup
    delete[] visited;

} 