#include <iostream>
using namespace std;
int climbingstairs_optimized(int n) {
    if (n == 0) return 1;  
    if (n == 1) return 1;  
    int prev1 = 1, prev2 = 1;  
    int curr;

    for (int i = 2; i <= n; i++) {
        curr = prev1 + prev2; 
        prev2 = prev1;  
        prev1 = curr;  
    }

    return curr; 
}

int main() {
    int n = 5;
    cout << "Ways to climb " << n << " stairs (Space Optimized): " << climbingstairs_optimized(n) << endl;
    return 0;
}
