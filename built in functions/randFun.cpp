#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int randomNum = rand() % 100 + 1;

    // Print the random number
    cout << "Random number between 1 and 100: " << randomNum << endl;

    return 0;
}
