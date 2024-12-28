//Network delay time(Hard).
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].emplace_back(v, w);
        }
        vector<int> dist(n + 1, INT_MAX); 
        dist[k] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.emplace(0, k); 

        while (!pq.empty()) {
            auto [time, node] = pq.top();
            pq.pop();
            if (time > dist[node]) continue;
            for (const auto& [neighbor, weight] : graph[node]) {
                int newDist = time + weight;
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.emplace(newDist, neighbor);
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

int main() {
    Solution solution;

    // Example 1
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int n1 = 4, k1 = 2;
    cout << "Example 1 Output: " << solution.networkDelayTime(times1, n1, k1) << endl;

    // Example 2
    vector<vector<int>> times2 = {{1, 2, 1}};
    int n2 = 2, k2 = 1;
    cout << "Example 2 Output: " << solution.networkDelayTime(times2, n2, k2) << endl;

    // Example 3
    vector<vector<int>> times3 = {{1, 2, 1}};
    int n3 = 2, k3 = 2;
    cout << "Example 3 Output: " << solution.networkDelayTime(times3, n3, k3) << endl;

    return 0;
}
