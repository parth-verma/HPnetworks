//
// Created by Parth Verma on 18/08/20.
//

#ifndef GRAPHS_UTILS_H
#define GRAPHS_UTILS_H
#include <gtest/gtest.h>
#include <types/EdgeView.h>
#include <types/NodeView.h>

bool assert_edges_equal(EdgeView G1, EdgeView G2);
bool assert_nodes_equal(NodeView G1, NodeView G2);
#endif //GRAPHS_UTILS_H
