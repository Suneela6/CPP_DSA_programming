#include <iostream>
using namespace std;

int main() {
    int n1;
    bool isPrime = true;  // Assume the number is prime initially

    cout << "Enter n1: ";
    cin >> n1;

    if (n1 <= 1) {
        // Numbers less than or equal to 1 are not prime numbers
        isPrime = false;
    } else {
        for (int i = 2; i <= n1 / 2; ++i) {
            if (n1 % i == 0) {
                isPrime = false;
                break;  // No need to check further, exit the loop
            }
        }
    }

    if (isPrime) {
        cout << n1 << " is a prime number." << endl;
    } else {
        cout << n1 << " is not a prime number." << endl;
    }

    return 0;
}
