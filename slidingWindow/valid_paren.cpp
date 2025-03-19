#include<iostream>
#include<string.h>
using namespace std;
int main()
{
  string s="()((a))";
  int n=s.size();
  int count=0;
  for(int i=0;i<n;i++){
    if(s[i]=='(' ){
        count++;
    }
    else if(s[i]==')'){
        count--;
        if (count < 0) { 
            cout << "Invalid" << endl;
            return 1;
        }
    }
  }
  if(count==0){
    cout<<"valid parenthesis:";
    return 0;
    }
  else{
    cout<<"not a valid parenthesis:";
    return 1;
    }
} 
