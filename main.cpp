/**
 * @file main.cpp
 * @author David Rohweder
 * @brief Main code to compare serial vs parallel Dijkstra's algorithm
 * @version 0.1
 * @date 2022-04-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */


// **** Includes

#include <sys/time.h>
#include <iostream>
#include "dijkstra.hpp"

// **** End Includes


// **** Function Region


/*

*/
int main(int argc, char *argv[]) {

    // *** Setup Environment

    double wcs, wce, serial_duration, parallel_duration;
    Graph* graph = new Graph; 
    int threadedVals[] = {1,2,4,8,10,15,20};

    // *** End Setup Environment

    for (int z = 0; z < 7; z++) {
        generate_Graph(graph); //printGraph(graph); -- utility for proof of concept

	    // benchmark serial dijkstra's implementation
	    get_walltime(&wcs);
	    serial_Dijkstra(graph);
	    get_walltime(&wce);
	    serial_duration = wce-wcs;
	
	    // benchmark parallel dijkstra's implementation
	    get_walltime(&wcs);
	    parallel_Dijkstra(graph);
	    get_walltime(&wce);
	    parallel_duration = wce-wcs;

        int correct = 1;
        // compare results
        for (int i = 0; i < N; i++) {
        
            if (graph->serial_distance[i] != graph->parallel_distance[i]) {
                printf("Outputs are invalid! Serial distance[%d]: %d, Parallel Distance[%d]: %d \n", i, graph->serial_distance[i], i, graph->parallel_distance[i]);        
                correct = 0;
                break;
            }
        }

        // Output walltimes
        if (correct == 1) {
            printf("Dijkstra's Wall times (Thread#=:%d)- Parallel: %f, Serial: %f\n", threadedVals[z], parallel_duration, serial_duration);		
        }
    }

    // Cleanup
    graph_Cleanup(graph);

    return 0; 
}


/*

*/
void get_walltime(double* wcTime) {
     struct timeval tp;
     gettimeofday(&tp, NULL);
     *wcTime = (double)(tp.tv_sec + tp.tv_usec/1000000.0);
}


// **** End Function Region