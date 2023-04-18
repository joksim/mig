#include <iostream>
#include <queue>
#include <vector>

using std::vector;
using std::queue;

bool bfs(int node, int color, vector<vector<int>>& graph, vector <int>& visited) {
    queue <int> q;
    q.push(node);
    visited[node] = color;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto adjNode: graph[curr]) {
            if (visited[adjNode] == -1) {
                q.push(adjNode);
                visited[adjNode] = !visited[curr];
            } else if (visited[adjNode] == visited[curr]) {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size(); // Get the node number
    vector <int> visited(n, -1); // Create visited vector for every node
    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            if (bfs(i, 0, graph, visited) == false)
                return false;
        }
    }
    return true;
}
