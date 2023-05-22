#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void dfs(vector<vector<int>>& graph, int startNode, vector<bool>& visited) {
    visited[startNode] = true;
    cout << startNode << " ";

    for (int neighbor : graph[startNode]) {
        if (!visited[neighbor]) {
            dfs(graph, neighbor, visited);
        }
    }
}

void dfsTraversal(vector<vector<int>>& graph, int startNode) {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);

    dfs(graph, startNode, visited);
}

int main() {
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges:\n";
    for (int i = 0; i < numEdges; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int startNode;
    cout << "Enter the starting node: ";
    cin >> startNode;

    cout << "DFS traversal starting from node " << startNode << ": ";
    dfsTraversal(graph, startNode);

    return 0;
}