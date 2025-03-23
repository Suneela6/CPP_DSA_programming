//shortest distance in binary-aze
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, pair<int, int> source, pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (grid[source.first][source.second] == 0 || grid[destination.first][destination.second] == 0)
            return -1;
        
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        queue<pair<int, pair<int, int>>> q;
        
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int r = it.second.first;
            int c = it.second.second;
            
            if (r == destination.first && c == destination.second)
                return dis;
            
            for (int i = 0; i < 4; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                    dist[newr][newc] = dis + 1;
                    q.push({dist[newr][newc], {newr, newc}});
                }
            }
        }
        return -1; // No path found
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    
    int sx, sy, dx, dy;
    cin >> sx >> sy >> dx >> dy;
    Solution obj;
    int result = obj.shortestPath(grid, {sx, sy}, {dx, dy});
    cout << result << endl;
    return 0;
}
