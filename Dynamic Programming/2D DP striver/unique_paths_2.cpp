// Given a ‘N’ * ’M’ maze with obstacles, count and return the number of unique paths to
// reach the right-bottom cell from the top-left cell. A cell in the given maze has a value
// '-1' if it is a blockage or dead-end, else 0. From a given cell, we are allowed to move
// to cells (i+1, j) and (i, j+1) only. Since the answer can be large,
// print it modulo 10^9 + 7.

// ----------------------------------SOLUTION-----------------------------------------------------


#include<bits/stdc++.h>

using namespace std;
int mod = (int)(1e9 + 7);


int helper(int i, int j,  vector< vector< int> > &mat,vector<vector<int>> &dp){
    if(i == 0 && j == 0){
        return 1;
    }
    if(i<0 || j<0){
        return 0;
    }
    if(mat[i][j] == -1){
        return 0;
    }
    if(dp[i][j] != -1) return dp[i][j];
    int left = helper(i-1,j,mat,dp);
    int up = helper(i,j-1,mat,dp);
    
    return dp[i][j] =(up + left)%mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return helper(n-1,m-1,mat,dp);
}

int main(){
    int n,m;
    cin>>n>>m;

    vector<vector<int>> mat;
    int temp;

    for(int i=0;i<n;i++){
        for (int j = 0; j < m; j++)
        {
            cin>>temp;
            mat[i][j] = temp;
        }

        
    }

    cout<<mazeObstacles(n,m,mat);

    return 0;
}

