//
// Created by Parth Verma on 19/08/20.
//

#ifndef GRAPHS_LATTICE_H
#define GRAPHS_LATTICE_H

#include <Graph/Graph.h>

Graph* hypercube_graph(int n);
Graph* grid_graph(std::vector<int> dims);
Graph* grid_graph(std::vector<std::vector<int>> dims);


#endif //GRAPHS_LATTICE_H
