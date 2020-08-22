//
// Created by Parth Verma on 08/06/20.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

#include <vector>
#include <unordered_map>
#include <types/EdgeViewWithData.h>
#include <types/NodeViewWithData.h>


class Graph {
protected:
    std::unordered_map<int, void *> node_attrs;
    std::unordered_map<int, std::unordered_map<int, std::pair<float, void *>>> adj_list;
    int node_counter = 0;
public:
    Graph() = default;

    explicit Graph(int n) {
        adj_list.reserve(n);
        node_attrs.reserve(n);
    }

    explicit Graph(const std::vector<std::tuple<int, int, float>>& edges);

    explicit Graph(const std::vector<std::tuple<int, int>>& edges);

    explicit Graph(const std::vector<std::tuple<int, int, float, void *>>& edges);

    explicit Graph(const std::vector<std::tuple<int, int, void *>>& edges);

    virtual // Adding and removing nodes and edges
    int add_node(void *attrs = nullptr);

    virtual void add_node(int id, void *attrs = nullptr);

    virtual void add_nodes_from(const std::vector<std::tuple<int, void *>> &nodes);

    virtual void add_nodes_from(const std::vector<void *> &nodes);

    virtual void add_nodes_from(std::vector<int> nodes);

    virtual void remove_node(int id);

    virtual void remove_nodes_from(std::vector<int> ids);

    virtual void add_edge(std::pair<int, int> edge, void *attrs = nullptr);

    virtual void add_edge(int u, int v, void *attrs = nullptr);

    virtual void add_edge(std::pair<int, int> edge, float weight, void *attrs = nullptr);

    virtual void add_edges_from(const std::vector<std::tuple<int, int, float>> &edges);

    virtual void add_edges_from(const std::vector<std::tuple<int, int>> &edges);

    virtual void add_attr_edges_from(const std::vector<std::tuple<int, int, float, void *>>& edges);

    virtual void add_attr_edges_from(const std::vector<std::tuple<int, int, void *>>& edges);

    virtual void remove_edge(std::pair<int, int> edge);

    virtual void remove_edges_from(const std::vector<std::pair<int, int>> &edges);

//    virtual void update(Graph G);

    virtual void update(const std::vector<std::tuple<int, int, float>>& edges);

    virtual void update(const std::vector<std::tuple<int, int>>& edges);

    virtual void update(const std::vector<std::tuple<int, int, float, void *>>& edges);

    virtual void update(const std::vector<std::tuple<int, int, void *>>& edges);

    virtual void update(const std::vector<std::tuple<int, void *>> &nodes);

    virtual void update(std::vector<int> nodes);

    virtual void clear();

    virtual void clear_edges();

    virtual NodeViewWithData nodes();

    virtual bool has_node(int id);

    virtual EdgeViewWithData edges();

    virtual EdgeViewWithData edges(int id);

    virtual EdgeViewWithData edges(const std::vector<int>& ids);

    virtual bool has_edge(std::pair<int, int> edge);
    virtual bool has_edge(int u,int v);

    virtual void *get_edge_data(std::pair<int, int> edge);

    virtual NodeViewWithData neighbors(int id);

    virtual //Counting
    int order();

    virtual int number_of_nodes();

    virtual std::unordered_map<int, int> degree();

    virtual std::unordered_map<int, int> degree(const std::vector<int>& nodes);

    virtual int degree(int id);
//    virtual std::unordered_map<int, float> weighted_degree();
//
//    virtual std::unordered_map<int, float> weighted_degree(const std::vector<int>& nodes);
//
//    virtual float weighted_degree(int id);

    virtual float size();

    virtual int number_of_edges();

    virtual int number_of_edges(std::pair<int, int> edge);

    //Copy
//    Graph(Graph &);
//
//    virtual Graph *subgraph(std::vector<int> nodes);
//
//    virtual Graph *edge_subgraph(std::vector<std::tuple<int, int>> edges);


};


#endif //GRAPHS_GRAPH_H
