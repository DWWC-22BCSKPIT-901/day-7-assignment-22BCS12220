//Minimum height tree(medium).
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    if (n == 1) return {0}; 
    vector<unordered_set<int>> adj(n);
    for (const auto& edge : edges) {
        adj[edge[0]].insert(edge[1]);
        adj[edge[1]].insert(edge[0]);
    }
    queue<int> leaves;
    for (int i = 0; i < n; ++i) {
        if (adj[i].size() == 1) {
            leaves.push(i);
        }
    }
    while (n > 2) {
        int leafCount = leaves.size();
        n -= leafCount; 

        for (int i = 0; i < leafCount; ++i) {
            int leaf = leaves.front();
            leaves.pop();
            for (int neighbor : adj[leaf]) {
                adj[neighbor].erase(leaf);
                if (adj[neighbor].size() == 1) {
                    leaves.push(neighbor);
                }
            }
        }
    }
    vector<int> result;
    while (!leaves.empty()) {
        result.push_back(leaves.front());
        leaves.pop();
    }

    return result;
}

int main() {
    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{1, 0}, {1, 2}, {1, 3}};
    vector<int> result1 = findMinHeightTrees(n1, edges1);
    cout << "MHT Roots (Example 1): ";
    for (int node : result1) {
        cout << node << " ";
    }
    cout << endl;

    // Example 2
    int n2 = 6;
    vector<vector<int>> edges2 = {{3, 0}, {3, 1}, {3, 2}, {3, 4}, {5, 4}};
    vector<int> result2 = findMinHeightTrees(n2, edges2);
    cout << "MHT Roots (Example 2): ";
    for (int node : result2) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
