//
// Created by Parth Verma on 18/08/20.
//

#include "EdgeView.h"

EdgeView::EdgeView(const EdgeViewWithData &a) {
    for(auto i:a){
        emplace_back(std::get<0>(i),std::get<1>(i));
    }
}

EdgeView::EdgeView(const std::vector<std::pair<int, int>> &a) : vector(a) {
}
