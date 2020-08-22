//
// Created by Parth Verma on 28/05/20.
//

#ifndef GRAPHS_CLASSIC_H
#define GRAPHS_CLASSIC_H


template<class T>
T *complete_graph(int n);

template<class T>
T *complete_graph(std::vector<int> nodes);

template<class T>
T *path_graph(int n);

template<class T>
T *path_graph(std::vector<int> nodes);


template<typename T>
T *cycle_graph(int n);

template<class T>
T *empty_graph(int n);

template<class T>
T *null_graph();


template<class T>
T *empty_graph(std::vector<int>& nodes);

template<class T>
T *parallel_empty_graph(int n);

template<class T>
T *star_graph(int n);

template<class T>
T *star_graph(std::vector<int> nodes);

template<class T>
T *wheel_graph(int n);

template<class T>
T *wheel_graph(std::vector<int> nodes);

template<typename T>
T *balanced_tree(int r, int h);

template<typename T>
T *full_rary_tree(int r, int n);


template<typename T>
T *trivial_graph();

template<typename T>
T *circulant_graph(int n, const std::vector<int> &offsets);

template<typename T>
T *circular_ladder_graph(int n);

template<typename T>
T *ladder_graph(int n);


Graph *binomial_tree(int n);


template<typename T>
T *barbell_graph(int m1,int m2);
Graph *turan_graph(int m1,int m2);
template<typename T>
T *lollipop_graph(int m1,int m2);
template<typename T>
T *lollipop_graph(std::vector<int> m1,std::vector<int> m2);

Graph *complete_multipartite_graph(std::vector<int> nodes);
Graph *complete_multipartite_graph(std::vector<std::vector<int>> nodes);

Graph* complete_bipartite_graph(int n1, int n2);

Graph *dorogovtsev_goltsev_mendes_graph(int n);
#endif //GRAPHS_CLASSIC_H
