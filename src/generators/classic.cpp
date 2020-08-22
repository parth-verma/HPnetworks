//
// Created by Parth Verma on 28/05/20.
//

#include <DiGraph/DiGraph.h>
#include <numeric>
#include <types/EdgeView.h>
#include "classic.h"
#include "../../tests/unit_tests/itertools.h"

//#include <omp.h>
template<class T>
T* complete_graph(int n){
    T* G = empty_graph<T>(n);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            G->add_edge(i,j);
        }
    }
    return G;
}
template<class T>
T* complete_graph(std::vector<int> nodes){
    int n = nodes.size();
    T* G = empty_graph<T>(nodes);

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            G->add_edge(nodes[i],nodes[j]);
        }
    }
    return G;
}
template<typename T>
T* cycle_graph(int n){
    T* G = empty_graph<T>(n);
    for(int i=0;i<n-1;i++){
        G->add_edge(i,i+1);
    }
    return G;
}

template<class T>
T* empty_graph(int n){
    T* G= new T(n);
    for(int i=0;i<n;i++) {
        G->add_node(i);
    }
    return G;
}
template<class T>
T* empty_graph(std::vector<int>& nodes){
    int n = nodes.size();
    T* G= new T(n);
    for(int i:nodes) {
        G->add_node(i);
    }
    return G;
}
template<class T>
T* parallel_empty_graph(int n){
    auto* G= new T(n);

    #pragma omp parallel for
    for(int i=0;i<n;i++) {
        G->add_node(i);
    }
    return G;
}
template<class T>
T* star_graph(int n){
    T *G = empty_graph<T>(n+1);
    for(int i=1;i<n+1;i++){
        G->add_edge(0,i);
    }
    return G;
}
template<class T>
T* star_graph(std::vector<int> nodes){
    int n = nodes.size();
    T *G = empty_graph<T>(nodes);
    for(int i=0;i<n;i++){
        G->add_edge(nodes[0],nodes[i]);
    }
    return G;
}
template<class T>
T* wheel_graph(int n){
    T *G = empty_graph<T>(n);
    for(int i=1;i<n-1;i++){
        G->add_edge(0,i);
        G->add_edge(i,i+1);
    }
    G->add_edge(n-1,1);
    G->add_edge(0,n-1);
    return G;
}

template<class T>
T* wheel_graph(std::vector<int> nodes){
    int n = nodes.size();
    T *G = empty_graph<T>(nodes);
    for(int i=1;i<n-1;i++){
        G->add_edge(nodes[0],nodes[i]);
        G->add_edge(nodes[i],nodes[i+1]);
    }
    G->add_edge(nodes[0],nodes[n-1]);
    G->add_edge(nodes[n-1],nodes[1]);
    return G;
}


template<typename T>
T* balanced_tree(int r,int h){
    T *G = new T();
    int curr_height = 0;
    int curr_id = 1;
    std::vector<int> curr_queue, next_queue={0};
    while(curr_height<h){
        curr_queue = next_queue;
        next_queue.clear();
        while(!curr_queue.empty()){
            auto x = curr_queue.front();
            curr_queue.erase(curr_queue.begin());
            for(int i=0;i<r;i++){
                G->add_edge(x,curr_id);
                next_queue.push_back(curr_id++);
            }
        }
        curr_height++;
    }


    return G;
}

template<typename T>
T* ladder_graph(int n){
    T* G = new T();
    for(int i=0;i<n;i++){
        G->add_edge(i,i+n);
    }
    return G;
}

template<typename T>
T* trivial_graph(){
    return empty_graph<T>(1);
}

template<typename T>
T* path_graph(int n){
    auto G = new T(n);
    for(int i=0;i<n-1;i++){
        G->add_edge(i,i+1);
    }
    return G;
}


template<typename T>
T* path_graph(std::vector<int> nodes){
    auto G = empty_graph<T>(nodes);
    for(int i=0;i<nodes.size()-1;i++){
        G->add_edge(nodes[i],nodes[i+1]);
    }
    return G;
}

template<typename T>
T* null_graph(){
    return new T();
}

template<typename T>
T* circulant_graph(int n, const std:: vector<int>& offsets){
    auto G = new T(n);
    for(int i = 0;i<n;i++){
        for(auto j: offsets){
            G->add_edge(i,(i-j)%n);
            G->add_edge(i,(i+j)%n);
        }
    }
    return G;
}

template<typename T>
T *circular_ladder_graph(int n) {
    auto G = ladder_graph<T>(n);
    G->add_edge(0,n-1);
    G->add_edge(n,2*n-1);
    return G;
}

Graph *complete_multipartite_graph(std::vector<int> nodes) {
    if (nodes.empty()){
        return new Graph();
    }
    nodes.insert(nodes.begin(),0);
    std::vector<int>accums;
    auto accumulator  = Accumulate(nodes.begin(),nodes.end());
    do{
        accums.push_back(*accumulator);
        ++accumulator;
    }while (accumulator.has_next());

    std::vector<std::pair<int,int>> extents;
    auto pairer  = Pairwise(accums.begin(),accums.end());
    do{
        extents.push_back(*pairer);
        ++pairer;
    }while (pairer.has_next());

    std::vector<std::vector<int>> subsets;
    for(auto i:extents){
        std::vector<int> a(i.second-i.first);
        std::iota(a.begin(),a.end(),i.first);
        subsets.push_back(a);
    }
    return complete_multipartite_graph(subsets);

}

Graph *complete_multipartite_graph(std::vector<std::vector<int>> nodes) {
    auto G = new Graph();
    if(nodes.empty()){
        return G;
    }
    for(const auto& i:nodes){
        G->add_nodes_from(i);
    }
    auto comb = Combinations(nodes.begin(),nodes.end(),2);
    do{
        auto subset1 = (*comb)[0];
        auto subset2 = (*comb)[1];
        auto prod = Product(subset1.begin(),subset1.end(),subset2.begin(),subset2.end());
        do{
            G->add_edge((*prod)[0],(*prod)[1]);
            ++prod;
        }while (prod.is_valid());
        ++comb;
    }
    while(comb.has_next());

    return G;
}

template<typename T>
T *lollipop_graph(int m1, int m2) {
    std::vector<int> a(m1);
    std::fill(a.begin(),a.end(),0);
    std::vector<int> b(m2);
    std::fill(b.begin(),b.end(),m1);
    return lollipop_graph<Graph>(a,b);
}

template<typename T>
T *lollipop_graph(std::vector<int> m1, std::vector<int> m2) {
    if (m1.size()<2 || m2.empty()){
        throw "Invalid Graph Description";
    }
    auto G = complete_graph<Graph>(m1);
    if (!m2.empty()) {
        G->add_edge(m1.back(), m2.front());
        for (int i = 0; i < m2.size() - 1; i++) {
            G->add_edge(m2[i], m2[i + 1]);
        }
    }
    return G;
}

Graph *complete_bipartite_graph(int n1, int n2) {
    auto G = new Graph;
    for(int i=0;i<n1+n2;i++){
        G->add_node(i);
    }
    for(int i=0;i<n1;i++){
        for(int j=n1;j<n2;j++){
            G->add_edge(i,j);
        }
    }
    return G;
}

template<typename T>
T *full_rary_tree(int r, int n) {
    T *G = new T();
    int num_nodes = 1;
    int curr_id = 1;
    std::vector<int> curr_queue, next_queue={0};
    while(num_nodes<n){
        curr_queue = next_queue;
        next_queue.clear();
        while(!curr_queue.empty() && num_nodes < n){
            auto x = curr_queue.front();
            curr_queue.erase(curr_queue.begin());
            for(int i=0;i<r && num_nodes<n;i++){
                G->add_edge(x,curr_id);
                num_nodes++;
                next_queue.push_back(curr_id++);
            }
        }
    }

    return G;
}

template<typename T>
T *barbell_graph(int m1, int m2) {
    T* G = complete_graph<T>(m1);
    std::vector<int> temp(m2-1);
    std::iota(temp.begin(),temp.end(),m1);

    if (m2>1){
        temp.resize(m2);
        std::iota(temp.begin(),temp.end(),m1);
        auto p = Pairwise(temp.begin(),temp.end());
        do{
            G->add_edge((*p).first,(*p).second);
            ++p;
        }while (p.has_next());
    }
    for(int u=m1+m2; u < 2*m1+m2;u++){
        for(int v = u+1; v< 2*m1+m2;v++ ){
            G->add_edge(u,v);
        }
    }
    G->add_edge(m1-1,m1);
    if (m2>0){
        G->add_edge(m1+m2-1,m1+m2);
    }
    return G;
}

Graph *turan_graph(int n, int r) {
    std::vector<int> partitions;
    for(int i=0;i<r-(n%r);i++){
        partitions.push_back(n/r);
    }
    for(int i=0;i<n%r;i++){
        partitions.push_back(n/r+1);
    }
    return complete_multipartite_graph(partitions);
}

Graph *binomial_tree(int n) {
    auto G = empty_graph<Graph>(1);
    int N=1;
    for(int i=0;i<n;i++){
        std::vector<std::pair<int,int>> edges;
        for(auto edge:EdgeView(G->edges())){
            G->add_edge(edge.first+N,edge.second+N);
        }
        G->add_edge(0,N);
        N *=2;
    }
    return G;
}

Graph *dorogovtsev_goltsev_mendes_graph(int n) {
    auto G = empty_graph<Graph>(0);
    G->add_edge(0,1);
    if (n==0){
        return G;
    }
    int new_node = 2;
    for(int i=1;i<n+1;i++){
        EdgeView edges = G->edges();
        for(auto j:edges){
            G->add_edge(new_node,j.first);
            G->add_edge(new_node,j.second);
            new_node++;
        }
    }
    return G;
}

template DiGraph* complete_graph<DiGraph>(int n);
template DiGraph* complete_graph<DiGraph>(std::vector<int> nodes);
template DiGraph* cycle_graph<DiGraph>(int n);
template DiGraph* empty_graph<DiGraph>(int n);
template DiGraph* empty_graph<DiGraph>(std::vector<int>& nodes);
template DiGraph* parallel_empty_graph<DiGraph>(int n);
template DiGraph* star_graph<DiGraph>(int n);
template DiGraph* star_graph<DiGraph>(std::vector<int> nodes);
template DiGraph* wheel_graph<DiGraph>(int n);
template DiGraph* wheel_graph<DiGraph>(std::vector<int> nodes);
template DiGraph* balanced_tree<DiGraph>(int r,int h);
template DiGraph* trivial_graph<DiGraph>();
template DiGraph* null_graph<DiGraph>();
template DiGraph* path_graph<DiGraph>(int n);
template DiGraph* path_graph<DiGraph>(std::vector<int> n);
template DiGraph* circulant_graph<DiGraph>(int n,const std::vector<int>& offsets);

template Graph* complete_graph<Graph>(int n);
template Graph* complete_graph<Graph>(std::vector<int> nodes);
template Graph* cycle_graph<Graph>(int n);
template Graph* empty_graph<Graph>(int n);
template Graph* empty_graph<Graph>(std::vector<int>& n);
template Graph* parallel_empty_graph<Graph>(int n);
template Graph* star_graph<Graph>(int n);
template Graph* star_graph<Graph>(std::vector<int> nodes);
template Graph* wheel_graph<Graph>(int n);
template Graph* wheel_graph<Graph>(std::vector<int> nodes);
template Graph* balanced_tree<Graph>(int r,int h);
template Graph* trivial_graph<Graph>();
template Graph* null_graph<Graph>();
template Graph* path_graph<Graph>(int n);
template Graph* path_graph<Graph>(std::vector<int> n);
template Graph* circular_ladder_graph<Graph>(int n);
template Graph* ladder_graph<Graph>(int n);
template Graph* circulant_graph<Graph>(int n,const std::vector<int>& offsets);
template Graph* full_rary_tree<Graph>(int r,int n);
template Graph* barbell_graph<Graph>(int m1,int m2);