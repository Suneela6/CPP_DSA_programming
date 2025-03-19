#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixToInfix(string postfix) {
    stack<string> st;

    for (int i = 0; i < postfix.length(); i++) {
        if (isalnum(postfix[i])) {
            st.push(string(1, postfix[i]));
        }
        else if (isOperator(postfix[i])) {
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            
            string result = "(" + operand1 + postfix[i] + operand2 + ")";
            
            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string postfix = "AB-DE+F*/";
    string infix = postfixToInfix(postfix);

    cout << "Infix expression: " << infix << endl;

    return 0;
}
