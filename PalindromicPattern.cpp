#include<iostream>
using namespace std;

int main() {
    int n = 4;  // You can change this value for a different size pattern

    for (int i = 1; i <= n; i++) {
        // Print leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        // Print decreasing numbers from i to 1
        for (int j = i; j >= 1; j--) {
            cout << j;
        }

        // Print increasing numbers from 2 to i
        for (int j = 2; j <= i; j++) {
            cout << j;
        }

        // Move to the next line after each row is printed
        cout << endl;
    }

    return 0;
}
