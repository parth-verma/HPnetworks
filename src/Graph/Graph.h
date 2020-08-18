//
// Created by Parth Verma on 08/06/20.
//

#ifndef GRAPHS_GRAPH_H
#define GRAPHS_GRAPH_H

typedef std::vector<std::tuple<int,void*>> NodeView;
typedef std::vector<std::tuple<int,int,float,void*>> EdgeView;

#include <vector>
#include <unordered_map>

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

    // Adding and removing nodes and edges
    int add_node(void *attrs = nullptr);

    void add_node(int id, void *attrs = nullptr);

    void add_nodes_from(const std::vector<std::tuple<int, void *>> &nodes);

    void add_nodes_from(const std::vector<void *> &nodes);

    void add_nodes_from(std::vector<int> nodes);

    void remove_node(int id);

    void remove_nodes_from(std::vector<int> ids);

    void add_edge(std::pair<int, int> edge, void *attrs = nullptr);
    void add_edge(int u, int v, void *attrs = nullptr);

    void add_edge(std::pair<int, int> edge, float weight, void *attrs = nullptr);

    void add_edges_from(const std::vector<std::tuple<int, int, float>> &edges);

    void add_edges_from(const std::vector<std::tuple<int, int>> &edges);

    void add_attr_edges_from(const std::vector<std::tuple<int, int, float, void *>>& edges);

    void add_attr_edges_from(const std::vector<std::tuple<int, int, void *>>& edges);

    void remove_edge(std::pair<int, int> edge);

    void remove_edges_from(const std::vector<std::pair<int, int>> &edges);

    void update(Graph G);

    void update(const std::vector<std::tuple<int, int, float>>& edges);

    void update(const std::vector<std::tuple<int, int>>& edges);

    void update(const std::vector<std::tuple<int, int, float, void *>>& edges);

    void update(const std::vector<std::tuple<int, int, void *>>& edges);

    void update(const std::vector<std::tuple<int, void *>> &nodes);

    void update(std::vector<int> nodes);

    void clear();

    void clear_edges();

    //Reporting
    NodeView nodes();

    bool has_node(int id);

    EdgeView edges();
    EdgeView edges(int id);
    EdgeView edges(const std::vector<int>& ids);

    bool has_edge(std::pair<int, int> edge);

    void *get_edge_data(std::pair<int, int> edge);

    NodeView neighbors(int id);

    //Counting
    int order();

    int number_of_nodes();

    std::unordered_map<int, float> degree();

    std::unordered_map<int, float> degree(const std::vector<int>& nodes);

    float degree(int id);

    float size();

    int number_of_edges();

    int number_of_edges(std::pair<int, int> edge);

    //Copy
    Graph(Graph &);

    Graph *subgraph(std::vector<int> nodes);

    Graph *edge_subgraph(std::vector<std::tuple<int, int>> edges);


};


#endif //GRAPHS_GRAPH_H
