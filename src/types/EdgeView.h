//
// Created by Parth Verma on 18/08/20.
//

#ifndef GRAPHS_EDGEVIEW_H
#define GRAPHS_EDGEVIEW_H


#include <vector>
#include "EdgeViewWithData.h"

class EdgeView: public std::vector<std::pair<int,int>> {
public:
    EdgeView(EdgeViewWithData const&a);
    EdgeView(std::vector<std::pair<int,int>> const&a);
    EdgeView(std::initializer_list<std::pair<int,int>> a):vector(a){};
};


#endif //GRAPHS_EDGEVIEW_H
