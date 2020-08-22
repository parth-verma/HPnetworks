//
// Created by Parth Verma on 27/07/20.
//

#include "unary.h"
DiGraph* complement(DiGraph* G){
    DiGraph* R = new DiGraph(G->number_of_nodes());
    for(auto i: G->nodes){
        R->add_node(i->id);
    }
    for(auto i:G->nodes){
        for(auto j:G->nodes){
            if(!G->has_edge(i,j) && i->id != j->id){
                R->add_edge(i->id,j->id);
            }
        }
    }
    return R;
}

DiGraph* reverse(DiGraph* G,bool copy){
    return G->reverse(copy);
}
