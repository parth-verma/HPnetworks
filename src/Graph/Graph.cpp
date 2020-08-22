//
// Created by Parth Verma on 08/06/20.
//

#include <queue>
#include <algorithm>
#include <utility>
#include "Graph.h"

// Store edges in adj_list such that smaller id is in the adj_list of larger id
int Graph::add_node(void *attrs) {
    int node_id;
    do{
        node_id= node_counter++;
    }while (has_node(node_id));

    adj_list[node_id] = std::unordered_map<int, std::pair<float, void *>>();
    node_attrs[node_id] = attrs;
    return node_id;
}

void Graph::add_nodes_from(const std::vector<void *> &nodes) {
    for (auto i: nodes) {
        add_node(i);
    }
}

bool Graph::has_node(int id) {
    return node_attrs.find(id) != node_attrs.end();
}

bool Graph::has_edge(std::pair<int, int> edge) {
    auto u = std::max(edge.first, edge.second);
    auto v = std::min(edge.first, edge.second);
    return has_node(u) && has_node(v) && adj_list[u].find(v) != adj_list[u].end();
}

int Graph::order() {
    return node_attrs.size();
}

int Graph::number_of_nodes() {
    return order();
}

int Graph::number_of_edges() {
    int count = 0;
    for (const auto &i: adj_list) {
        count += i.second.size();
    }
    return count;
}

float Graph::size() {
    float ans = 0;
    for (const auto &i: adj_list) {
        for (const auto &j:i.second) {
            ans += j.second.first;
        }
    }
    return ans;
}

NodeViewWithData Graph::neighbors(int id) {
    NodeViewWithData ans;
    for(const auto& i:adj_list){
        if(i.first == id){
            for(const auto& j:i.second){
                ans.emplace_back(j.first,node_attrs[j.first]);
            }
        }
        else if(i.second.find(id)!=i.second.end()){
            ans.emplace_back(i.first,node_attrs[i.first]);
        }
    }
    return ans;
}

void Graph::clear_edges() {
    for(const auto& i:adj_list){
        adj_list[i.first].clear();
    }
}

void Graph::clear() {
    adj_list.clear();
    node_attrs.clear();

}

void *Graph::get_edge_data(std::pair<int, int> edge) {
    auto u = std::max(edge.first,edge.second);
    auto v = std::min(edge.first,edge.second);
    if (has_edge(edge)){
        return adj_list[u][v].second;
    }
    return nullptr;
}

void Graph::remove_edge(std::pair<int, int> edge) {
    auto u = std::max(edge.first,edge.second);
    auto v = std::min(edge.first,edge.second);
    if (has_edge(edge))
        adj_list[u].erase(adj_list[u].find(v));
}

void Graph::remove_edges_from(const std::vector<std::pair<int, int>>& edges) {
    for(auto i:edges)
        remove_edge(i);
}

void Graph::remove_node(int id) {
    if (has_node(id)) {
        node_attrs.erase(node_attrs.find(id));
        adj_list.erase(adj_list.find(id));
        for(const auto& i:adj_list){
            adj_list[i.first].erase(adj_list[i.first].find(id));
        }
    }

}

void Graph::remove_nodes_from(std::vector<int> ids) {
    for(auto i: ids){
        remove_node(i);
    }
}

void Graph::add_node(int id, void *attrs) {
    if(!has_node(id)){
        node_counter = std::max(id+1,node_counter);
        adj_list[id] = std::unordered_map<int, std::pair<float, void *>>();
        node_attrs[id] = attrs;
    }

}

void Graph::add_nodes_from(const std::vector<std::tuple<int, void *>>& nodes) {
    for(auto i: nodes){
        add_node(std::get<int>(i),std::get<void*>(i));
    }
}

void Graph::add_nodes_from(std::vector<int> nodes) {
    for(auto i:nodes){
        add_node(i);
    }
}

void Graph::add_edge(std::pair<int, int> edge, void *attrs) {
    add_edge(edge,1,attrs);
}

void Graph::add_edge(std::pair<int, int> edge, float weight, void *attrs) {
    if(!has_edge(edge)){
        auto u = std::max(edge.first,edge.second);
        auto v = std::min(edge.first,edge.second);
        add_node(u);
        add_node(v);
        adj_list[u][v] = std::make_pair(weight,attrs);
    }
}

void Graph::add_edges_from(const std::vector<std::tuple<int, int, float>>& edges) {
    for(auto i: edges){
        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)),std::get<float>(i));
    }
}

void Graph::add_edges_from(const std::vector<std::tuple<int, int>>& edges) {
    for(auto i: edges){
        add_edge(std::make_pair(std::get<0>(i),std::get<1>(i)));
    }
}

NodeViewWithData Graph::nodes() {
    NodeViewWithData ans;
    for(auto i:node_attrs){
        ans.emplace_back(i.first,i.second);
    }
    return ans;
}

EdgeViewWithData Graph::edges() {
    EdgeViewWithData ans;
    for(const auto& i:adj_list){
        for(auto j:i.second){
            ans.emplace_back(i.first,j.first,j.second.first,j.second.second);
        }
    }
    return ans;
}

int Graph::number_of_edges(std::pair<int, int> edge) {
    return has_edge(edge)?1:0;
}

void Graph::update(std::vector<int> nodes) {
    add_nodes_from(std::move(nodes));
}

void Graph::update(const std::vector<std::tuple<int, void *>>& nodes) {
    add_nodes_from(nodes);
}

void Graph::add_attr_edges_from(const std::vector<std::tuple<int, int, void *>>& edges){
    for(auto i:edges){
        add_edge(std::make_tuple(std::get<0>(i),std::get<1>(i)),std::get<2>(i));
    }
}
void Graph::add_attr_edges_from(const std::vector<std::tuple<int, int, float, void *>>& edges){
    for(auto i:edges){
        add_edge(std::make_tuple(std::get<0>(i),std::get<1>(i)),std::get<2>(i),std::get<3>(i));
    }
}

Graph::Graph(const std::vector<std::tuple<int, int, float>>& edges) {
    add_edges_from(edges);
}
Graph::Graph(const std::vector<std::tuple<int, int>>& edges){
    add_edges_from(edges);
}
Graph::Graph(const std::vector<std::tuple<int, int, float, void *>>& edges) {
    add_attr_edges_from(edges);
}
Graph::Graph(const std::vector<std::tuple<int, int, void *>>& edges) {
    add_attr_edges_from(edges);
}

// TODO: Modify to update existing edges and create if not exist
void Graph::update(const std::vector<std::tuple<int, int, float>>& edges) {
    add_edges_from(edges);
}
void Graph::update(const std::vector<std::tuple<int, int>>& edges) {
    add_edges_from(edges);
}void Graph::update(const std::vector<std::tuple<int, int, float,void*>>& edges) {
    add_attr_edges_from(edges);
}
void Graph::update(const std::vector<std::tuple<int, int,void*>>& edges) {
    add_attr_edges_from(edges);
}

EdgeViewWithData Graph::edges(int id) {
    EdgeViewWithData ans;
    for(const auto& i:adj_list){
        if (i.first == id){
            for(auto j:i.second)
                ans.emplace_back(i.first,j.first,j.second.first,j.second.second);
        }
        else if (i.second.find(id) != i.second.end()){
            ans.emplace_back(i.first,id,i.second.find(id)->second.first,i.second.find(id)->second.second);
        }
    }
    return ans;
}

EdgeViewWithData Graph::edges(const std::vector<int>& ids) {
    EdgeViewWithData ans;
    for(auto i:ids){
        auto l = edges(i);
        ans.insert(ans.end(),l.begin(),l.end());
    }
    auto ip = std::unique(ans.begin(),ans.end());
    ans.resize(std::distance(ans.begin(),ip));
    return ans;
}

int Graph::degree(int id) {
    return edges(id).size();
}

std::unordered_map<int, int> Graph::degree(const std::vector<int>& nodes) {
    std::unordered_map<int, int> ans;
    for(auto i:nodes){
        ans[i] = degree(i);
    }
    return ans;
}

std::unordered_map<int, int> Graph::degree() {
    std::vector<int> nodes;
    for(auto i: Graph::nodes()){
        nodes.push_back(std::get<int>(i));
    }
    return degree(nodes);
}

void Graph::add_edge(int u, int v,void* attrs) {
    add_edge(std::make_pair(u,v),attrs);
}

bool Graph::has_edge(int u, int v) {
    return has_edge(std::make_pair(u,v));
}


