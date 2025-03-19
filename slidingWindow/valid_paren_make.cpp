#include <iostream>
#include <string>
using namespace std;

bool isValid(string &s, int index, int count) {
    if (index == s.length()) {
        return count == 0; 
    }

    if (count < 0) {
        return false;
    }

    if (s[index] == '(') {
        return isValid(s, index + 1, count + 1);
    } 
    else if (s[index] == ')') {
        return isValid(s, index + 1, count - 1);
    } 
    else if (s[index] == '*') {
        return isValid(s, index + 1, count + 1) || 
               isValid(s, index + 1, count - 1) || 
               isValid(s, index + 1, count);
    }

    return false; 
}

bool checkValidString(string s) {
    return isValid(s, 0, 0);
}

int main() {
    string s = "(*))";
    cout << (checkValidString(s) ? "Valid" : "Invalid") << endl;
    return 0;
}
