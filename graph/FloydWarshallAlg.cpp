#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 1e9; 
            }
            if (i == j) {
                matrix[i][j] = 0; 
            }
        }
    }

    for (int k = 0; k < n; k++) { 
        for (int i = 0; i < n; i++) { 
            for (int j = 0; j < n; j++) { 
                if (matrix[i][k] != 1e9 && matrix[k][j] != 1e9) {
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (matrix[i][i] < 0) {
            cout << "Graph contains a negative cycle." << endl;
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 1e9) {
                matrix[i][j] = -1; 
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of vertices: ";
    cin >> n;

    vector<vector<int>> matrix(n, vector<int>(n));
    cout << "Enter the adjacency matrix (use -1 for no edge):" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    shortest_distance(matrix);

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == -1) {
                cout << "INF ";
            } else {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
