#include <iostream>
#include <vector>
using namespace std;

void dfs(int row, int col, vector<vector<char>>& mat, vector<vector<int>>& visited, 
         vector<int>& delrow, vector<int>& delcol) {
    int n = mat.size();
    int m = mat[0].size();
    
    // Mark cell as visited
    visited[row][col] = 1;

    // Explore all 4 directions
    for (int i = 0; i < 4; i++) {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
            mat[nrow][ncol] == 'O' && !visited[nrow][ncol]) {
            dfs(nrow, ncol, mat, visited, delrow, delcol);
        }
    }
}

void replaceSurroundedRegions(vector<vector<char>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Movement vectors for up, right, down, left
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};

    // Mark boundary-connected 'O' cells using DFS
    for (int j = 0; j < m; j++) {
        if (!visited[0][j] && mat[0][j] == 'O') {
            dfs(0, j, mat, visited, delrow, delcol);
        }
        if (!visited[n - 1][j] && mat[n - 1][j] == 'O') {
            dfs(n - 1, j, mat, visited, delrow, delcol);
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && mat[i][0] == 'O') {
            dfs(i, 0, mat, visited, delrow, delcol);
        }
        if (!visited[i][m - 1] && mat[i][m - 1] == 'O') {
            dfs(i, m - 1, mat, visited, delrow, delcol);
        }
    }

    // Convert all unvisited 'O' cells to 'X'
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'O' && !visited[i][j]) {
                mat[i][j] = 'X';
            }
        }
    }
}

int main() {
    vector<vector<char>> mat = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'},
        {'X', 'X', 'O', 'O'}
    };

    replaceSurroundedRegions(mat);

    // Print the result
    for (const auto& row : mat) {
        for (char c : row) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}
