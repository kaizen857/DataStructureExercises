#ifndef _HAP_HPP_
#define _HAP_HPP_

#include <iostream>
#include <set>
#include <vector>
#include <queue>

class Map
{
private:
    int vertices;
    std::vector<std::set<int>> adjList;

public:
    // 构造函数
    Map(int v) :
        vertices(v), adjList(v) {}
    Map(int v, std::vector<std::set<int>> adj) :
        vertices(v), adjList(adj) {}
    void addEdge(int u, int v)
    {
        adjList[u].insert(v);
        adjList[v].insert(u);
    }

    // 深度优先搜索
    void dfs(int start)
    {
        std::vector<bool> visited(vertices, false);
        dfsUtil(start, visited);
        std::cout << "\n";
    }

    void dfsUtil(int v, std::vector<bool> &visited)
    {
        visited[v] = true;
        std::cout << v << " ";

        for (auto neighbor : adjList[v])
        {
            if (!visited[neighbor])
            {
                dfsUtil(neighbor, visited);
            }
        }
    }

    // 广度优先搜索
    void bfs(int start)
    {
        std::vector<bool> visited(vertices, false);
        std::queue<int> q;

        visited[start] = true;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            std::cout << v << " "; // 访问当前节点

            for (int neighbor : adjList[v])
            {
                if (!visited[neighbor])
                {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
        std::cout << "\n";
    }
};

#endif