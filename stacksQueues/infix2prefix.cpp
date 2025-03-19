#include<iostream>
#include<string.h>
#include<algorithm>//for reverse
#include<stack>
using namespace std;
int priority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    } 
    if (op == '*' || op == '/') {
        return 2;
    } 
    if (op == '^') {
        return 3;
    }
    return 0;
}
string conver2InfixPostfix(string s){
    int i=0;
    stack<char> st;
    string ans="";
    int n=s.size();
    while (i < n)
    {
        // if((s[i] >= 'A' && s[i] <= 'z') || (s[i]>='a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <='9' )){
        //     ans+=s[i];
        // }
        if (isalnum(s[i])) {
            ans += s[i];
        }
        else if(s[i] == '('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while (!st.empty() && st.top()!='(')
            {
            ans+=st.top();
            st.pop();
            }
            st.pop();
        }
        else{
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans+=st.top();
        st.pop();
    }
    return ans;
}
string infix2prefix(string s) {
    reverse(s.begin(), s.end());  
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        }
        else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    string result = conver2InfixPostfix(s);
    
    reverse(result.begin(), result.end());
    return result;
}
int main()
{
    string s="(A+B)*C-D+F";
    string answer=infix2prefix(s);
    cout<<"prefix expression is: "<<answer<<endl;
}

