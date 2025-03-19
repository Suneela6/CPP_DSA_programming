#include<iostream>
using namespace std;
class fun_obj{
    public:
    int operator()(int a,int b){
        return a+b;
    }
};
int main(){
    fun_obj f;
    int res=f(5,5);
    cout<<"the res is:"<<res<<endl;
    return 0;
}