#include <iostream>
#include <vector>

using std::vector;

bool dfs(int node, int color, vector<vector<int>>& graph, vector <int>& visited) {
    visited[node] = color;
    for (auto adjNode: graph[node]) {
        if (visited[adjNode] == -1) {
            if (dfs(adjNode, !color, graph, visited) == false)
                return false;
        } else if (visited[adjNode] == color) {
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector <int> visited(n, -1);
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (dfs(i, 0, graph, visited) == false)
                return false;
        }
    }
    return true;
}
