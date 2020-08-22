//
// Created by Parth Verma on 08/06/20.
//

#include <queue>
#include <algorithm>
#include "DiGraph.h"


DiGraph::DiGraph(DiGraph &a) {
}

DiGraph::DiGraph(const std::vector<std::tuple<int, int, float>> &edges) : Graph(edges) {

}

DiGraph::DiGraph(const std::vector<std::tuple<int, int>> &edges) : Graph(edges) {

}

DiGraph::DiGraph(const std::vector<std::tuple<int, int, float, void *>> &edges) : Graph(edges) {

}

DiGraph::DiGraph(const std::vector<std::tuple<int, int, void *>> &edges) : Graph(edges) {

}


void DiGraph::add_edge(std::pair<int, int> edge, void *attrs) {
    add_edge(edge,1,attrs);
}

void DiGraph::add_edge(int u, int v, void *attrs) {
    add_edge(std::make_pair(u, v), attrs);
}

void DiGraph::add_edge(std::pair<int, int> edge, float weight, void *attrs) {
    if (!has_edge(edge)){
        add_node(edge.first);
        add_node(edge.second);
        adj_list[edge.first][edge.second] = std::make_pair(weight,attrs);
    }
}

//void DiGraph::add_edges_from(const std::vector<std::tuple<int, int, float>> &edges) {
//    for(auto i:edges){
//        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)),std::get<float>(i));
//    }
//}

//void DiGraph::add_edges_from(const std::vector<std::tuple<int, int>> &edges) {
//    for(auto i:edges){
//        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)));
//    }
//}

//void DiGraph::add_attr_edges_from(const std::vector<std::tuple<int, int, float, void *>> &edges) {
//    for(auto i:edges){
//        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)),std::get<float>(i),std::get<void*>(i));
//    }
//}

//void DiGraph::add_attr_edges_from(const std::vector<std::tuple<int, int, void *>> &edges) {
//    for(auto i:edges){
//        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)),std::get<void*>(i));
//    }
//}

void DiGraph::remove_edge(std::pair<int, int> edge) {
    if (has_edge(edge)){
        adj_list[edge.first].erase(adj_list[edge.first].find(edge.second));
    }
}

//void DiGraph::remove_edges_from(const std::vector<std::pair<int, int>> &edges) {
//    Graph::remove_edges_from(edges);
//}

//void DiGraph::update(Graph G) {
//    Graph::update(G);
//}

void DiGraph::update(const std::vector<std::tuple<int, int, float>> &edges) {
    Graph::update(edges);
}

void DiGraph::update(const std::vector<std::tuple<int, int>> &edges) {
    Graph::update(edges);
}

void DiGraph::update(const std::vector<std::tuple<int, int, float, void *>> &edges) {
    Graph::update(edges);
}

void DiGraph::update(const std::vector<std::tuple<int, int, void *>> &edges) {
    Graph::update(edges);
}

void DiGraph::update(const std::vector<std::tuple<int, void *>> &nodes) {
    Graph::update(nodes);
}

void DiGraph::update(std::vector<int> nodes) {
    Graph::update(nodes);
}


NodeViewWithData DiGraph::nodes() {
    return Graph::nodes();
}

bool DiGraph::has_node(int id) {
    return Graph::has_node(id);
}

EdgeViewWithData DiGraph::edges() {
    return Graph::edges();
}

EdgeViewWithData DiGraph::edges(int id) {
    return Graph::edges(id);
}

EdgeViewWithData DiGraph::edges(const std::vector<int> &ids) {
    return Graph::edges(ids);
}

bool DiGraph::has_edge(std::pair<int, int> edge) {
    return has_node(edge.first) && has_node(edge.second) && adj_list[edge.first].find(edge.second) != adj_list[edge.first].end();
}

void *DiGraph::get_edge_data(std::pair<int, int> edge) {
    if (has_edge(edge)){
        return adj_list[edge.first][edge.second].second;
    }
    return nullptr;
}

NodeViewWithData DiGraph::neighbors(int id) {
    return Graph::neighbors(id);
}

int DiGraph::order() {
    return Graph::order();
}

int DiGraph::number_of_nodes() {
    return Graph::number_of_nodes();
}

std::unordered_map<int, int> DiGraph::degree() {
    return Graph::degree();
}

std::unordered_map<int, int> DiGraph::degree(const std::vector<int> &nodes) {
    return Graph::degree(nodes);
}

int DiGraph::degree(int id) {
    return Graph::degree(id);
}

float DiGraph::size() {
    return Graph::size();
}

int DiGraph::number_of_edges() {
    return Graph::number_of_edges();
}

int DiGraph::number_of_edges(std::pair<int, int> edge) {
    return Graph::number_of_edges(edge);
}

bool DiGraph::has_edge(int u, int v) {
    return has_edge(std::make_pair(u,v));
}

//DiGraph::DiGraph(Graph &graph) : Graph(graph) {
//
//}
//
//Graph *DiGraph::subgraph(std::vector<int> nodes) {
//    return Graph::subgraph(nodes);
//}
//
//Graph *DiGraph::edge_subgraph(std::vector<std::tuple<int, int>> edges) {
//    return Graph::edge_subgraph(edges);
//}

//std::unordered_map<int, float> DiGraph::out_degree() {
//    std::unordered_map<int, float> ans;
//    for(const auto& i:adj_list){
//        float sum = 0;
//        for(auto j:i.second){
//            sum+=j.second.first;
//        }
//        ans[i.first] = sum;
//    }
//    return ans;
//}

//DiGraph *DiGraph::subgraph(std::vector<DirectedNode *> nodes) {
//    DiGraph *G = new DiGraph;
//
//    for (auto i: nodes) {
//        G->add_node(i->id);
//    }
//    for (auto i: nodes) {
//        if (!G->has_node(i->id))
//            continue;
//        for (auto edge:i->outgoing_edges) {
//            if (G->has_node(edge->to->id)) {
//                G->add_edge(i->id, edge->to->id);
//            }
//        }
//    }
//    return G;
//}

//
//
//DiGraph *DiGraph::reverse(bool copy) {
//    if (copy){
//        DiGraph* R = new DiGraph(this->number_of_nodes());
//        for(auto i: this->nodes){
//            R->add_node(i->id);
//        }
//        for(auto i:this->edges){
//            R->add_edge(i->to->id,i->from->id);
//        }
//        return R;
//    }
//
//    for(int i=0;i< this->number_of_edges();i++){
//        DirectedEdge edge = *(this->edges[i]);
//        this->delete_edge(this->edges[i]);
//        this->add_edge(edge.to->id,edge.from->id);
//    }
//    return this;
//}
