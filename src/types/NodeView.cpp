//
// Created by Parth Verma on 19/08/20.
//

#include "NodeView.h"

NodeView::NodeView(const NodeViewWithData &a) {
    for(auto i:a){
        push_back(std::get<0>(i));
    }
}

NodeView::NodeView(const std::vector<int> &a) : vector(a) {
}
