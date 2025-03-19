#include <iostream>
using namespace std;

void func() {
    static int i = 0; 
    int j=0;
    i++; 
    j++;
    cout << i << "  " << j << "\n"; 
}

int main() {
func(); 
func();
func();
func(); 
func(); 
func();
func();
func();
}
