#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool detectCycle(int i, vector<int>& visited, vector<vector<int>>& adj) {
        visited[i] = 1;
        queue<pair<int, int>> q;
        q.push({i, -1});

        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();

            for (auto it : adj[node]) {
                if (!visited[it]) {
                    visited[it] = 1;
                    q.push({it, node});
                }
                else if (it != parent) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& adj) {
        vector<int> visited(V, 0);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (detectCycle(i, visited, adj)) 
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges in the graph: ";
    cin >> V >> E;

    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    if (obj.isCycle(V, adj)) {
        cout << "Cycle detected in the graph\n";
    } else {
        cout << "No cycle detected\n";
    }

    return 0;
}
