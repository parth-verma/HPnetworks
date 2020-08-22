//
// Created by Parth Verma on 19/08/20.
//

#ifndef GRAPHS_NODEVIEW_H
#define GRAPHS_NODEVIEW_H
#include <vector>
#include "types/NodeViewWithData.h"
class NodeView:public std::vector<int> {
public:
    NodeView(NodeViewWithData const&a);
    NodeView(std::vector<int> const&a);
    NodeView(std::initializer_list<int> a):vector(a){};
};


#endif //GRAPHS_NODEVIEW_H
