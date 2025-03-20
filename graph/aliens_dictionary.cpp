//DETECT CYCLE IN DAGUSING BFS TOPOLOGICAL SORT
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool detectCycle(vector<vector<int>>& adj, int V) {
    vector<int> indegree(V, 0);
    queue<int> q;
    int count = 0;

    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        count++; 

        for (auto it : adj[node]) {
            indegree[it]--;
            if (indegree[it] == 0) {
                q.push(it);
            }
        }
    }

    return count != V;
}

int main() {
    int V, E;
    cout << "Enter number of vertices and edges: ";
    cin >> V >> E;
    
    vector<vector<int>> adj(V);
    
    cout << "Enter the edges (u -> v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    if (detectCycle(adj, V)) {
        cout << "Cycle detected in the graph.\n";
    } else {
        cout << "No cycle in the graph.\n";
    }

    return 0;
}
