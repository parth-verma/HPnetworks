//
// Created by Parth Verma on 18/08/20.
//

#include "function.h"

bool comp(std::pair<int, int> i, std::pair<int, int> j) {
    return i.first < j.first;
}

std::vector<int> degree_histogram(Graph *G) {

    std::unordered_map<int, int> counter;
    auto c = G->degree();
    for (auto i:c) {
        counter[i.second] += 1;
    }

    int max_count = -1;
    for (auto i:counter) {
        max_count = std::max(max_count, i.first);
    }

    std::vector<int> ans(max_count + 1);
    for (auto i:counter) {
        ans[i.first] = i.second;
    }
    return ans;
}
