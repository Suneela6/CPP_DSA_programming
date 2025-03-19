// ninja has a "GRID" of size "R"*"C" each cell of the grid contains some
//chocolates. Ninja has two friends Alice and Bob, and he wants to 
//collect as many chocolates as possible with the help of his friend
//initially,Alice is in the top-left position i.e,(0,0), and Bob is in the top-right
//place i.e,(0,"C"-1) in the grid. Each of them can move from their current cell to the cell
//just below them. when anyone passes from any cell, he will pick all
//chocolates in it, and then the number of chocolates in that cell will
//become zero. if both stay in the same cell ,only one of them will pick the chococlates in it.
//if alice or Bob is at(i,j) then they can move to (i+1,j),(i+1,j-1) or(i+1,j+1).
//they will always stay inside the "grid".
//your task is to find the maximum number of chococlates ninja can collect with the help of
//his friends by following the above rules
#include<iostream>
#include<vector>
using namespace std;
int cherryPickUp(int i,int j1,int j2,int rows,int cols,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
    if(j1<0 || j1>=cols || j2<0 || j2>=cols){
        return -1e9;
    }
    if(i==rows-1){
        if(j1==j2){
            return grid[i][j1];
        }
        else{
            return grid[i][j1]+grid[i][j2];
        }
    }
    if (dp[i][j1][j2] != -1) {
        return dp[i][j1][j2];
    }
    int maxi=-1e9;
    for(int dj1=-1;dj1<=1;dj1++){
        for(int dj2=-1;dj2<=1;dj2++){
            int val=0;
            if(j1==j2){
                val= grid[i][j1];
            }
            else{
                val=grid[i][j1]+grid[i][j2];
            }
            val+=cherryPickUp(i+1,j1+dj1,j2+dj2,rows,cols,grid,dp);
            maxi=max(maxi,val);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int main(){
    int rows=3;
    int cols=4;
    vector<vector<int>> grid={
        {2,3,1,2},
        {3,4,2,2},
        {5,6,3,5}
    };
    vector<vector<vector<int>>> dp(rows,vector<vector<int>>(cols,vector<int>(cols,-1)));
    int ans=cherryPickUp(0,0,cols-1,rows,cols,grid,dp);
    cout<<"max number of cherry pickups by ninja is:"<<ans;
}