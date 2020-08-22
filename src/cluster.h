//
// Created by Parth Verma on 18/08/20.
//

#ifndef GRAPHS_CLUSTER_H
#define GRAPHS_CLUSTER_H

#include <Graph/Graph.h>
#include "types/typedefs.h"
std::unordered_map<int,int> triangles(Graph* G);
std::unordered_map<int,int> triangles(Graph* G,std::vector<int> nodes);
float average_clustering(Graph *G, std::vector<int> nodes,edge_weight_attr_callable weight= nullptr,bool count_zeros = true);
float average_clustering(Graph *G, edge_weight_attr_callable weight= nullptr,bool count_zeros = true);

#endif //GRAPHS_CLUSTER_H
