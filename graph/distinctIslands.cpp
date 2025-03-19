//given a boolean 2d matrix of size n*m .you have to find the number
//of distinct  islands where a group  of coonected 1s(horizontally or vertically)
//forms an island .two islands are considered to be distinct if and only if one island is equal to another 
//(not  rotated or  reflected).
//example grid[][]={{1,1,0,0,0},
//                  {1,1,0,0,0},
//                  {0,0,0,1,1},
//                  {0,0,0,1,1}};
//         output:1
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int row, int col, int baseRow, int baseCol, vector<vector<int>> &grid, vector<vector<int>> &visited, vector<pair<int, int>> &shape) {
    int n = grid.size(), m = grid[0].size();
    visited[row][col] = 1;
    shape.push_back({row - baseRow, col - baseCol}); 

    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++) {
        int newRow = row + delRow[i];
        int newCol = col + delCol[i];

        if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
            grid[newRow][newCol] == 1 && visited[newRow][newCol] == 0) {
            dfs(newRow, newCol, baseRow, baseCol, grid, visited, shape);
        }
    }
}

int countDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visited(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> distinctShapes; 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1 && visited[i][j] == 0) {
                vector<pair<int, int>> shape;
                dfs(i, j, i, j, grid, visited, shape);
                distinctShapes.insert(shape); 
            }
        }
    }
    
    return distinctShapes.size();
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    cout << "Number of distinct islands: " << countDistinctIslands(grid) << endl;
    return 0;
}
