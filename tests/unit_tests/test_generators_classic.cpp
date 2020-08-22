//
// Created by Parth Verma on 18/08/20.
//

#include <Graph/Graph.h>
#include "gtest/gtest.h"
#include "utils.h"
#include <generators/classic.h>
#include <function.h>
#include <isomorphism/isomorph.h>
#include <connected.h>
#include <DiGraph/DiGraph.h>
#include <cluster.h>
#include <generators/lattice.h>

TEST(TestGenerators, test_balanced_tree) {
    std::vector<std::pair<int, int>> config = {{2, 2},
                                               {6, 2},
                                               {3, 3}};
    for (auto i:config) {
        auto r = i.first;
        auto h = i.second;
        auto t = balanced_tree<Graph>(r, h);
        int order = t->order();
        ASSERT_EQ(order, (int(pow(r, h + 1)) - 1) / (r - 1));
//        ASSERT_TRUE(is_connected(t));
        ASSERT_EQ(t->size(), order - 1);
        auto dh = degree_histogram(t);
        ASSERT_EQ(dh[0], 0);
        ASSERT_EQ(dh[1], int(pow(r, h)));
        ASSERT_EQ(dh[r], 1);
        ASSERT_EQ(dh[r + 1], order - int(pow(r, h)) - 1);
        ASSERT_EQ(dh.size(), r + 2);
        delete t;
    }
}

TEST(TestGenerators, test_balanced_tree_star) {
    auto t = balanced_tree<Graph>(2, 1);
    auto l = star_graph<Graph>(2);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
    t = balanced_tree<Graph>(5, 1);
    l = star_graph<Graph>(5);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
    t = balanced_tree<Graph>(10, 1);
    l = star_graph<Graph>(10);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
}

TEST(TestGenerators, test_balanced_tree_path) {
    auto t = balanced_tree<Graph>(1, 4);
    auto l = path_graph<Graph>(5);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
}

TEST(TestGenerators, test_full_rary_tree) {
    int r = 2, n = 9;
    auto t = full_rary_tree<Graph>(r, n);
    ASSERT_EQ(t->order(), n);
    ASSERT_TRUE(is_connected(t));
    auto dh = degree_histogram(t);
    ASSERT_EQ(dh[0], 0);
    ASSERT_EQ(dh[1], 5);
    ASSERT_EQ(dh[r], 1);
    ASSERT_EQ(dh[r + 1], 9 - 5 + 1);
    ASSERT_EQ(dh.size(), r + 2);
    delete t;
}

TEST(TestGenerators, test_full_rary_tree_balanced) {
    auto t = full_rary_tree<Graph>(2, 15);
    auto l = balanced_tree<Graph>(2, 3);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
}

TEST(TestGenerators, test_full_rary_tree_path) {
    auto t = full_rary_tree<Graph>(1, 10);
    auto l = path_graph<Graph>(10);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete t;
    delete l;
}

TEST(TestGenerators, test_full_rary_tree_3_20) {
    auto t = full_rary_tree<Graph>(3, 20);
    ASSERT_EQ(t->order(), 20);
    delete t;
}


TEST(TestGenerators, test_barbell_graph) {
    int m1 = 3, m2 = 5;
    auto t = barbell_graph<Graph>(m1, m2);
    ASSERT_EQ(t->number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(t->number_of_edges(), m1 * (m1 - 1) + m2 + 1);
    delete t;
    m1 = 4;
    m2 = 10;
    t = barbell_graph<Graph>(m1, m2);
    ASSERT_EQ(t->number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(t->number_of_edges(), m1 * (m1 - 1) + m2 + 1);
    delete t;
    m1 = 3, m2 = 20;
    t = barbell_graph<Graph>(m1, m2);
    ASSERT_EQ(t->number_of_nodes(), 2 * m1 + m2);
    ASSERT_EQ(t->number_of_edges(), m1 * (m1 - 1) + m2 + 1);
    delete t;

    m1 = 1;
    m2 = 20;
    ASSERT_ANY_THROW(barbell_graph<Graph>(m1, m2));

    m1 = 5;
    m2 = -2;
    ASSERT_ANY_THROW(barbell_graph<Graph>(m1, m2));

    m1 = 2;
    m2 = 5;
    t = barbell_graph<Graph>(m1, m2);
    auto l = path_graph<Graph>(m2 + 4);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete l;
    delete t;

    m1 = 2;
    m2 = 10;
    t = barbell_graph<Graph>(m1, m2);
    l = path_graph<Graph>(m2 + 4);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete l;
    delete t;

    m1 = 2;
    m2 = 20;
    t = barbell_graph<Graph>(m1, m2);
    l = path_graph<Graph>(m2 + 4);
    ASSERT_TRUE(could_be_isomorphic(t, l));
    delete l;
    delete t;

//    mb = nx.barbell_graph(m1, m2, create_using=nx.MultiGraph())
//    assert_edges_equal(mb.edges(), b.edges())
}

TEST(TestGenerators, test_binomial_tree) {
    for (int i = 0; i < 5; i++) {
        auto b = binomial_tree(i);
        ASSERT_EQ(b->number_of_nodes(), int(pow(2, i)));
        ASSERT_EQ(b->number_of_edges(), int(pow(2, i))-1);
        delete b;

    }
}

TEST(TestGenerators, test_complete_graph) {
    for (auto m : {0, 1, 3, 5}) {
        auto g = complete_graph<Graph>(m);
        ASSERT_EQ(g->number_of_nodes(), m);
        ASSERT_EQ(g->number_of_edges(), m * (m - 1) / 2);
        delete g;
    }
//    mg = nx.complete_graph(m, create_using=nx.MultiGraph)
//    assert_edges_equal(mg.edges(), g.edges())
}

TEST(TestGenerators, test_complete_digraph) {
    for (auto m : {0, 1, 3, 5}) {
        auto g = complete_graph<Graph>(m);
        ASSERT_EQ(g->number_of_nodes(), m);
        ASSERT_EQ(g->number_of_edges(), m * (m - 1));
        delete g;
    }
//    mg = nx.complete_graph(m, create_using=nx.MultiGraph)
//    assert_edges_equal(mg.edges(), g.edges())
}

TEST(TestGenerators, test_circular_ladder_graph) {
    auto G = circular_ladder_graph<Graph>(5);
//    mG = nx.circular_ladder_graph(5, create_using = nx.MultiGraph)
//    assert_edges_equal(mG.edges(), G.edges())
    delete G;
}

TEST(TestGenerators, test_circulant_graph) {
    auto Ci6_1 = circulant_graph<Graph>(6, {1});
    auto C6 = cycle_graph<Graph>(6);
    ASSERT_TRUE(assert_edges_equal(Ci6_1->edges(), C6->edges()));
    delete Ci6_1;
    delete C6;

    auto Ci7 = circulant_graph<Graph>(7, {1, 2, 3});
    auto K7 = complete_graph<Graph>(7);
    ASSERT_TRUE(assert_edges_equal(Ci7->edges(), K7->edges()));
    delete Ci7;
    delete K7;

    auto Ci6_1_3 = circulant_graph<Graph>(6, {1, 3});
    auto K3_3 = complete_bipartite_graph(3, 3);
    ASSERT_TRUE(could_be_isomorphic(Ci6_1_3, K3_3));
    delete Ci6_1_3;
    delete K3_3;
}

TEST(TestGenerators, test_cycle_graph) {
    auto G = cycle_graph<Graph>(4);
    ASSERT_TRUE(assert_edges_equal(G->edges(), {{0, 1},
                                                {0, 3},
                                                {1, 2},
                                                {2, 3}}));
//    mG = nx.cycle_graph(4, create_using = nx.MultiGraph)
//    assert_edges_equal(mG.edges(),[(0, 1), (0, 3), (1, 2), (2, 3)])
    delete G;
    G = cycle_graph<DiGraph>(4);
    ASSERT_FALSE(G->has_edge(2, 1));
    ASSERT_TRUE(G->has_edge(1, 2));
    delete G;
}

TEST(TestGenerators, test_dorogovtsev_goltsev_mendes_graph) {
    auto G = dorogovtsev_goltsev_mendes_graph(0);
    ASSERT_TRUE(assert_edges_equal(G->edges(), {{0, 1}}));
    ASSERT_TRUE(assert_nodes_equal(G->nodes(), {0, 1}));
    delete G;
    G = dorogovtsev_goltsev_mendes_graph(1);
    ASSERT_TRUE(assert_edges_equal(G->edges(), {{0, 1},
                                                {0, 2},
                                                {1, 2}}));
    ASSERT_FLOAT_EQ(average_clustering(G), 1.0);
    auto tr = triangles(G);
    ASSERT_TRUE(std::all_of(tr.begin(), tr.end(), [](std::pair<int, int> i) { return i.second == 1; }));
    delete G;
    G = dorogovtsev_goltsev_mendes_graph(10);
    ASSERT_EQ(G->number_of_nodes(), 29526);
    ASSERT_EQ(G->number_of_edges(), 59049);
    ASSERT_EQ(G->degree(0), 1024);
    ASSERT_EQ(G->degree(1), 1024);
    ASSERT_EQ(G->degree(2), 1024);
    delete G;
}

TEST(TestGenerators, test_ladder_graph) {
    std::vector<std::pair<int, Graph *>> tests = {{0,  empty_graph<Graph>(0)},
                                                  {1,  path_graph<Graph>(2)},
                                                  {2,  hypercube_graph(2)},
                                                  {10, grid_graph({2, 10})}};
    for (auto i:tests) {
        auto G = ladder_graph<Graph>(i.first);
        ASSERT_TRUE(could_be_isomorphic(G, i.second));
        delete G;
        delete i.second;
    }

//    g = nx.ladder_graph(2)
//    mg = nx.ladder_graph(2, create_using = nx.MultiGraph)
//    assert_edges_equal(mg.edges(), g.edges())
}

TEST(TestGenerators, test_lollipop_graph) {
    std::vector<std::pair<int, int>> tests = {{3, 5},
                                              {4, 10},
                                              {3, 20}};
    for (auto i:tests) {
        int m1 = i.first;
        int m2 = i.second;
        auto b = lollipop_graph<Graph>(m1, m2);
        ASSERT_EQ(b->number_of_nodes(), m1 + m2);
        ASSERT_EQ(b->number_of_edges(), m1 * (m1 - 1) / 2 + m2);
        delete b;
    }

    ASSERT_ANY_THROW(lollipop_graph<Graph>(1, 20));
    ASSERT_ANY_THROW(lollipop_graph<Graph>(5, -2));

    tests = {{2, 5},
             {2, 10},
             {2, 20}};
    for (auto i:tests) {
        int m1 = i.first, m2 = i.second;
        auto b = lollipop_graph<Graph>(m1, m2);
        auto t = path_graph<Graph>(m2 + 2);
        ASSERT_TRUE(could_be_isomorphic(b, t));
        delete t;
        delete b;
    }

//    mb = nx.lollipop_graph(m1, m2, create_using = nx.MultiGraph)
//    assert_edges_equal(mb.edges(), b.edges())

    auto g = lollipop_graph<Graph>({1, 2, 3, 4}, {4, 5, 6, 7});

    ASSERT_EQ(g->number_of_nodes(), 7);
    ASSERT_FLOAT_EQ(g->size(), 9);
}

TEST(TestGenerators, test_null_graph) {
    auto G = null_graph<Graph>();
    ASSERT_EQ(G->number_of_nodes(), 0);
    delete G;
}

TEST(TestGenerators, test_path_graph) {
    auto p = path_graph<Graph>(0);
    auto t = null_graph<Graph>();
    ASSERT_TRUE(could_be_isomorphic(p, t));
    delete p;
    delete t;

    p = path_graph<Graph>(1);
    t = empty_graph<Graph>(1);
    ASSERT_TRUE(could_be_isomorphic(p, t));
    delete p;
    delete t;

    p = path_graph<Graph>(10);
    ASSERT_TRUE(is_connected(p));
//    ASSERT_EQ(
//    sorted(d
//    for
//    n, d
//    in
//    p.degree()), {1, 1, 2, 2, 2, 2, 2, 2, 2, 2})
    ASSERT_EQ(p->order() - 1, p->size());

    auto dp = path_graph<DiGraph>(3);
    ASSERT_TRUE(dp->has_edge(0, 1));
    ASSERT_FALSE(dp->has_edge(1, 0));

//    mp = nx.path_graph(10, create_using = nx.MultiGraph)
//    assert_edges_equal(mp.edges(), p.edges())
}

TEST(TestGenerators, test_star_graph) {
    auto G = star_graph<Graph>(0);
    auto T = empty_graph<Graph>(1);
    ASSERT_TRUE(could_be_isomorphic(G, T));
    delete G;
    delete T;

    G = star_graph<Graph>(1);
    T = path_graph<Graph>(2);
    ASSERT_TRUE(could_be_isomorphic(G, T));
    delete G;
    delete T;

    G = star_graph<Graph>(2);
    T = path_graph<Graph>(3);
    ASSERT_TRUE(could_be_isomorphic(G, T));
    delete G;
    delete T;

    G = star_graph<Graph>(1);
    T = complete_bipartite_graph(1, 5);
    ASSERT_TRUE(could_be_isomorphic(G, T));
    delete G;
    delete T;


    G = star_graph<Graph>(10);
//    assert
//    sorted(d
//    for
//    n, d
//    in
//    s.degree()) == [1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 10]


//    ms = star_graph(10, create_using = nx.MultiGraph)
//    assert_edges_equal(ms.edges(), G.edges())
}

TEST(TestGenerators, test_trivial_graph) {
    auto G = trivial_graph<Graph>();
    ASSERT_EQ(G->number_of_nodes(), 1);
    delete G;
}

TEST(TestGenerators, test_turan_graph) {
    auto G = turan_graph(13, 4);
    ASSERT_EQ(G->number_of_edges(), 63);
    auto T = complete_multipartite_graph({3, 4, 3, 3});
    ASSERT_TRUE(could_be_isomorphic(G, T));

    delete G;
    delete T;
}

TEST(TestGenerators, test_wheel_graph) {
    std::vector<std::pair<int, Graph *>> tests = {{0, null_graph<Graph>()},
                                                  {1, empty_graph<Graph>(1)},
                                                  {2, path_graph<Graph>(2)},
                                                  {3, complete_graph<Graph>(3)},
                                                  {4, complete_graph<Graph>(4)}};
    for (auto i:tests) {
        int n = i.first;
        Graph *G = i.second;
        auto g = wheel_graph<Graph>(n);
        ASSERT_TRUE(could_be_isomorphic(g, G));
        delete g;
        delete G;
    }
    auto g = wheel_graph<Graph>(10);
//    assert
//    sorted(d
//    for
//    n, d
//    in
//    g.degree()) == [3, 3, 3, 3, 3, 3, 3, 3, 3, 9]


//    mg = nx.wheel_graph(10, create_using = nx.MultiGraph())
//    assert_edges_equal(mg.edges(), g.edges())

}

TEST(TestGenerators, test_complete_1_partite_graph) {
    auto G = complete_multipartite_graph({3});
    auto H = empty_graph<Graph>(3);
    ASSERT_TRUE(assert_nodes_equal(G->nodes(), H->nodes()));
    ASSERT_TRUE(assert_edges_equal(G->edges(), H->edges()));
    delete G;
    delete H;
}

TEST(TestGenerators, test_complete_2_partite_graph) {
    auto G = complete_multipartite_graph({2, 3});
    auto H = complete_bipartite_graph(2, 3);
    ASSERT_TRUE(assert_nodes_equal(G->nodes(), H->nodes()));
    ASSERT_TRUE(assert_edges_equal(G->edges(), H->edges()));
    delete G;
    delete H;
}

//def test_complete_multipartite_graph(self):
//"""Tests for generating the complete multipartite graph."""
//G = nx.complete_multipartite_graph(2, 3, 4)
//blocks = [(0, 1), (2, 3, 4), (5, 6, 7, 8)]
//# Within each block, no two vertices should be adjacent.
//for block in blocks:
//for u, v in itertools.combinations_with_replacement(block, 2):
//assert v not in G[u]
//assert G.nodes[u] == G.nodes[v]
//# Across blocks, all vertices should be adjacent.
//for (block1, block2) in itertools.combinations(blocks, 2):
//for u, v in itertools.product(block1, block2):
//assert v in G[u]
//assert G.nodes[u] != G.nodes[v]


