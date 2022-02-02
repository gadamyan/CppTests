//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#include "core/algorithms/GraphAlgorithms.h"
#include <gtest/gtest.h>

namespace {

using namespace cpptests::core::algorithms;

TEST(GraphTest, verify_the_connected_edges_of_the_graph)
{
    Graph graph(6);
    graph.addEdge(1, 3);
    graph.addEdge(1, 2);
    graph.addEdge(3, 4);

    EXPECT_TRUE(breadthFirstSearch(graph, 1, 4));
    EXPECT_FALSE(breadthFirstSearch(graph, 1, 5));
}
}
