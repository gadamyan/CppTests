//
//  TestFactory.hpp
//  cpptests
//
//  Created by Adamyan, Gevorg on 10/28/18.
//  Copyright © 2018 Adamyan, Gevorg. All rights reserved.
//

#pragma once

#include <algorithm>
#include <vector>
#include <queue>
#include <set>

namespace cpptests::core::algorithms {

class Graph
{
public:
    Graph(int size)
    : m_edges(size)
    {
    }

    void add_edge(int edge1, int edge2)
    {
        m_edges[edge1].push_back(edge2);
        m_edges[edge2].push_back(edge1);
    }

    size_t size() const
    {
        return m_edges.size();
    }

    const std::vector<int>& operator[](size_t index) const
    {
        return m_edges.at(index);
    }

private:
    std::vector<std::vector<int>> m_edges;
};

bool bfs(const Graph& graph, int edge1, int edge2)
{
    std::vector<bool> visited(graph.size(), false);
    std::queue<int> container;
    container.push(edge1);
    while (!container.empty())
    {
        const int current_edge = container.front();
        container.pop();
        visited[current_edge] = true;
        for (const int next_edge : graph[current_edge])
        {
            if (edge2 == next_edge)
            {
                return true;
            }
            if (!visited[next_edge])
            {
                container.push(next_edge);
            }
        }
    }
    return false;
}

//class DijkstraGraph
//{
//public:
//    void dijkstra(int source, int n)
//    {
//        std::vector<int> distances(n, std::numeric_limits<int>::max());
//        distances[source] = 0;
//        std::set<std::pair<int, int>> sequence;
//        sequence.insert({0, source});
//        while (!sequence.empty())
//        {
//            const auto it = sequence.cbegin();
//            int current = it->second;
//            sequence.erase(it);
//            for (auto a : m_graph[current])
//            {
//                <#statements#>
//            }
//        }
//    }
//
//private:
//    std::vector<std::vector<std::pair<int, int>>> m_graph;
//};

}
