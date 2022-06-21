// You have been given an N*M matrix filled with integer numbers, find the maximum sum that can be obtained from a path starting from 
// any cell in the first row to any cell in the last row.
// From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right.

// ----------------------------------SOLUTION-----------------------------------------------------

 
#include<bits/stdc++.h>

using namespace std;

// int helper(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp,int n, int m){
//     if(j<0 || i<0 || j>=m) return -1e8;
//     if(i==0){
//         return matrix[i][j];
//     }
//     if(dp[i][j] != -1) return dp[i][j];
//     int up = matrix[i][j] + helper(i-1,j,matrix, dp ,n,m);
//     int up_left = matrix[i][j] + helper(i-1,j-1,matrix, dp ,n,m);
//     int up_right = matrix[i][j] + helper(i-1,j+1,matrix, dp ,n,m);
    
//     return dp[i][j] =  max(up, max(up_left,up_right));
// }

int getMaxPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
//     vector<vector<int>> dp(n, vector<int>(m,-1));
//     int maxx = -1e8;
//     for(int j =0 ; j<m;j++){
//         int p = helper(n-1,j,matrix,dp,n,m);
//         maxx = max(p,maxx);
//     }
//     return maxx;
    
    int dp[n][m];
    int up,up_left,up_right;
    for(int i = 0; i<n;i++){
        for(int j = 0; j< m; j++){
            up = -1e9;
            up_left = -1e9;       
            up_right = -1e9;
     
                if(i == 0){ 
                    dp[i][j] = matrix[i][j];
//                     cout<<"It is "<<dp[i][j]<<endl;
                       continue;
                }
                up = matrix[i][j] + dp[i-1][j];
                if(j-1>=0)
                up_left = matrix[i][j] + dp[i-1][j-1];
                if(j+1<m)
                up_right = matrix[i][j] + dp[i-1][j+1];
            
            dp[i][j] = max(up,max(up_left,up_right));
//             cout<<"val is "<<dp[i][j]<<endl;
        }
    }
    
    int maxx = -1e9;
    for(int j=0;j<m;j++){
//         cout<<"it is "<<dp[n-1][j]<<endl;
        maxx = max(maxx,dp[n-1][j]);
    }
    
    return maxx;
    
    
}

int main() {

  vector<vector<int> > matrix{{1,2,10,4},
                              {100,3,2,1},
                              {1,1,20,2},
                              {1,2,2,1}};
  
  cout<<getMaxPathSum(matrix);
}