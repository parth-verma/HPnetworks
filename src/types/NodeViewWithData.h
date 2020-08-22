//
// Created by Parth Verma on 19/08/20.
//

#ifndef GRAPHS_NODEVIEWWITHDATA_H
#define GRAPHS_NODEVIEWWITHDATA_H


#include <vector>

class NodeViewWithData: public std::vector<std::pair<int,void*>> {
public:
    NodeViewWithData()= default;
//    NodeViewWithData(const vector <std::pair<int, void *>, std::allocator<std::pair<int, void *>>> &x);
};


#endif //GRAPHS_NODEVIEWWITHDATA_H
