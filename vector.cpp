#include<iostream>
#include<vector>
using namespace std;
int main()
{
   vector<int> vec;
   vec.push_back(5); 
   vec.push_back(3);
   vec.push_back(8);
   vec.push_back(9);
   vec.push_back(10);
   vec.pop_back();
   for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
            cout<<*it<<endl;
   }
} 