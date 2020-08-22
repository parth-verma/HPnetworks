//
// Created by Parth Verma on 27/07/20.
//

#ifndef GRAPHS_UNARY_H
#define GRAPHS_UNARY_H

#include <DiGraph/DiGraph.h>

DiGraph* complement(DiGraph* G);

DiGraph* reverse(DiGraph* G,bool copy=true);

#endif //GRAPHS_UNARY_H
