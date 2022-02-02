//
//  CppTests
//
//  Created by Gevorg Adamyan
//

#pragma once

#include <algorithm>
#include <vector>
#include <queue>

namespace cpptests::core::algorithms {

class Graph {
public:
    explicit Graph(int size)
    : mEdges(size)
    {}

    void addEdge(int edge1, int edge2) {
        mEdges[edge1].push_back(edge2);
        mEdges[edge2].push_back(edge1);
    }

    size_t size() const {
        return mEdges.size();
    }

    const std::vector<int>& operator[](size_t index) const {
        return mEdges.at(index);
    }

private:
    std::vector<std::vector<int>> mEdges;
};

bool breadthFirstSearch(const Graph& graph, int edge1, int edge2) {
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> container;
    container.push(edge1);
    while (!container.empty()) {
        const int currentEdge = container.front();
        container.pop();
        visited[currentEdge] = true;
        for (const int nextEdge : graph[currentEdge]) {
            if (edge2 == nextEdge) {
                return true;
            }
            if (!visited[nextEdge]) {
                container.push(nextEdge);
            }
        }
    }
    return false;
}

}
