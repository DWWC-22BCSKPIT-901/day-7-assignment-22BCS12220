//BFS of graph link
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsTraversal(int V, vector<vector<int>>& adj) {
    vector<int> bfs;            
    vector<bool> visited(V, false); 
    queue<int> q;               
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return bfs;
}

int main() {
    // Example 1
    vector<vector<int>> adj1 = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};
    vector<int> result1 = bfsTraversal(5, adj1);
    cout << "BFS Traversal (Example 1): ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    // Example 2
    vector<vector<int>> adj2 = {{1, 2}, {0, 2}, {0, 1, 3, 4}, {2}, {2}};
    vector<int> result2 = bfsTraversal(5, adj2);
    cout << "BFS Traversal (Example 2): ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    // Example 3
    vector<vector<int>> adj3 = {{1}, {0, 2, 3}, {1}, {1, 4}, {3}};
    vector<int> result3 = bfsTraversal(5, adj3);
    cout << "BFS Traversal (Example 3): ";
    for (int node : result3) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
