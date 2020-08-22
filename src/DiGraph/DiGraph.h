//
// Created by Parth Verma on 08/06/20.
//

#ifndef GRAPHS_DIGRAPH_H
#define GRAPHS_DIGRAPH_H
#include "Graph/Graph.h"

class DiGraph: public Graph{
public:

    DiGraph()= default;
    explicit DiGraph(int n){
        adj_list.reserve(n);
    }
    DiGraph(DiGraph &a);

    explicit DiGraph(const std::vector<std::tuple<int, int, float>> &edges);

    explicit DiGraph(const std::vector<std::tuple<int, int>> &edges);

    explicit DiGraph(const std::vector<std::tuple<int, int, float, void *>> &edges);

    explicit DiGraph(const std::vector<std::tuple<int, int, void *>> &edges);

    void add_edge(std::pair<int, int> edge, void *attrs= nullptr) override;

    void add_edge(int u, int v, void *attrs= nullptr) override;

    void add_edge(std::pair<int, int> edge, float weight, void *attrs= nullptr) override;

    void remove_edge(std::pair<int, int> edge) override;

//    void update(Graph G) override;

    void update(const std::vector<std::tuple<int, int, float>> &edges) override;

    void update(const std::vector<std::tuple<int, int>> &edges) override;

    void update(const std::vector<std::tuple<int, int, float, void *>> &edges) override;

    void update(const std::vector<std::tuple<int, int, void *>> &edges) override;

    void update(const std::vector<std::tuple<int, void *>> &nodes) override;

    void update(std::vector<int> nodes) override;

    NodeViewWithData nodes() override;

    bool has_node(int id) override;

    EdgeViewWithData edges() override;

    EdgeViewWithData edges(int id) override;

    EdgeViewWithData edges(const std::vector<int> &ids) override;

//    EdgeView out_edges() ;
//
//    EdgeView out_edges(int id) ;
//
//    EdgeView out_edges(const std::vector<int> &ids) ;
//
//    EdgeView in_edges() ;
//
//    EdgeView in_edges(int id) ;
//
//    EdgeView in_edges(const std::vector<int> &ids) ;

    bool has_edge(std::pair<int, int> edge) override;
    bool has_edge(int u, int v) override;

    void *get_edge_data(std::pair<int, int> edge) override;

    NodeViewWithData neighbors(int id) override;
//    NodeView successors(int id);
//    NodeView predecessor(int id);

    int order() override;

    int number_of_nodes() override;

    std::unordered_map<int, int> degree() override;

    std::unordered_map<int, int> degree(const std::vector<int> &nodes) override;

    int degree(int id) override;

//    std::unordered_map<int, float> in_degree();
//
//    std::unordered_map<int, float> in_degree(const std::vector<int> &nodes);
//
//    float in_degree(int id);

//    std::unordered_map<int, float> out_degree();
//
//    std::unordered_map<int, float> out_degree(const std::vector<int> &nodes);
//
//    float out_degree(int id);

    float size() override;

    int number_of_edges() override;

    int number_of_edges(std::pair<int, int> edge) override;

//    DiGraph(Graph &graph);
//
//    Graph *subgraph(std::vector<int> nodes) override;
//
//    Graph *edge_subgraph(std::vector<std::tuple<int, int>> edges) override;
//
//    Graph* to_undirected();
//    DiGraph* reverse();
};



#endif //GRAPHS_DIGRAPH_H
