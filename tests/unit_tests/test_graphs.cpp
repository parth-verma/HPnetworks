//
// Created by Parth Verma on 18/08/20.
//

#include "gtest/gtest.h"
#include "Graph/Graph.h"
#include "generators/classic.h"
TEST(TestGraph,test_has_node){
    auto* G = complete_graph<Graph>(3);
    ASSERT_TRUE(G->has_node(0));
    ASSERT_TRUE(G->has_node(1));
    ASSERT_TRUE(G->has_node(2));
    ASSERT_FALSE(G->has_node(3));
    ASSERT_FALSE(G->has_node(-1));
    delete G;
}

TEST(TestGraph,test_has_edge){
    auto* G = complete_graph<Graph>(3);
    ASSERT_TRUE(G->has_edge(0,1));
    ASSERT_TRUE(G->has_edge(0,2));
    ASSERT_TRUE(G->has_edge(1,2));
    ASSERT_FALSE(G->has_edge(3,1));
    ASSERT_TRUE(G->has_edge(1,0));
    delete G;
}

TEST(TestGraph,test_add_node){
    auto* G = complete_graph<Graph>(3);
    G->add_node();
    ASSERT_EQ(G->number_of_nodes(),4);
    G->add_node(0);
    ASSERT_EQ(G->number_of_nodes(),4);
    delete G;
}
TEST(TestGraph,test_clear){
    auto* G = complete_graph<Graph>(3);
    G->clear_edges();
    ASSERT_EQ(G->number_of_edges(),0);
    ASSERT_EQ(G->number_of_nodes(),3);
    G->clear();
    ASSERT_EQ(G->number_of_edges(),0);
    ASSERT_EQ(G->number_of_nodes(),0);
    delete G;
}