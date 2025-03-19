// #include<iostream>
// #include<vector>
// using namespace std;
// vector<int> pairSum(vector<int> pair,int target){
//         vector<int> ans;
//         int n=pair.size();
//         for(int i=0;i<n;i++){
//             for(int j=i+1;j<n;j++){
//                 if(pair[i]+pair[j]==target){
//                     ans.push_back(i);
//                     ans.push_back(j);
//                 }
//             }
//         }
//         return ans;
// }
// int main(){
//     vector<int> pair={1,2,3,4,5,6};
//     int target=7;
//     vector<int> ans=pairSum(pair,target);
//     cout<<"i="<<ans[0]<<",j="<<ans[1];
//     return 0;
// }
// //above is bruteforce with o(n^2)

#include<iostream>
#include<vector>
using namespace std;
vector<int> pairSum(vector<int> pair,int target){
        vector<int> ans;
        int n=pair.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int pairSum1=pair[i]+pair[j];
            if(pairSum1<target){
                i++;
            }
            else if(pairSum1>target){
                j--;
            }
            else{
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
        return ans;
}
int main(){
    vector<int> pair={1,2,3,4,5,8};
    int target=7;
    vector<int> ans=pairSum(pair,target);
    cout<<"i="<<ans[0]<<",j="<<ans[1];
    return 0;
}

