project(${CMAKE_PROJECT_NAME}_lib)

set(HEADER_FILES )
set(SOURCE_FILES )

add_library(${CMAKE_PROJECT_NAME}_lib STATIC
#        approximation/connectivity.cpp approximation/connectivity.h
#        communities/community_utils.h communities/community_utils.cpp
#        components.cpp components.h
        DiGraph/DiGraph.cpp DiGraph/DiGraph.h
        Graph/Graph.cpp Graph/Graph.h
#        generators/classic.cpp generators/classic.h
#        tournament.cpp tournament.h
#        traversal_iterators.cpp traversal_iterators.h
#        shortest_paths.cpp shortest_paths.h
#        approximation/vertex_cover.cpp approximation/vertex_cover.h
#        assortativity/neighbour_degree.cpp assortativity/neighbour_degree.h
#        DiGraph/DirectedEdge.cpp DiGraph/DirectedEdge.h
#        DiGraph/DirectedNode.cpp DiGraph/DirectedNode.h
#        dag.cpp dag.h
#        Graph/Node.cpp Graph/Node.h
        #        approximation/kcomponents.cpp approximation/kcomponents.h
#        operators/unary.cpp operators/unary.h
#        generators/stochastic.cpp generators/stochastic.h
        )