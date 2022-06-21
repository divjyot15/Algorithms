// You are given a triangular array/list 'TRIANGLE'. Your task is to return the minimum path sum to reach from the
//  top to the bottom row.
// The triangle array will have N rows and the i-th row, where 0 <= i < N will have i + 1 elements.
// You can move only to the adjacent number of row below each step. For example, if you are at index j in row i,
// then you can move to i or i + 1 index in row j + 1 in each step.


// ----------------------------------SOLUTION-----------------------------------------------------


#include<bits/stdc++.h>
using namespace std;

// int helper(int i, int j, vector<vector<int>>& triangle,int n, vector<vector<int>> &dp){
//     if(i == n-1 && j<=n-1){
//         return triangle[i][j];
//     }
//     if(i>=n || j>i){
//         return 1e9;
//     }
//     if(dp[i][j] != -1) return dp[i][j];
//     int down = triangle[i][j] + helper(i+1,j,triangle,n,dp);
//     int left_down = triangle[i][j] + helper(i+1,j+1,triangle,n,dp);
    
//     return dp[i][j] = min(down,left_down);
// }

int minimumPathSum(vector<vector<int>> &triangle, int n){
	vector<vector<int>> dp(n,vector<int>(n,-1));
//     return helper(0,0,triangle,n,dp);
//    int dp[n][n];
    int up,right_up;
   for(int i =n-1; i>=0;i--){
       for(int j =i;j>=0;j--){
           if(i==n-1){
               dp[i][j] = triangle[i][j];
               }
           else{
               up = triangle[i][j] + dp[i+1][j];
               right_up = triangle[i][j] + dp[i+1][j+1];
               dp[i][j] = min(up,right_up);
           }
           
       }
   } 
    return dp[0][0];
    
}

int main(){
    vector<vector<int>> triangle;
    int n;
    cin>>n; 
    int temp;
    for(int i=0;i<n;i++){
        vector<int> x;
        for(int j=0;j<=i;j++){
            cin>>temp;
            x.push_back(temp);
        }
        triangle.push_back(x);
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<triangle[i][j]<<" ";
        }
        cout<<endl;
    }

    // cout<<minimumPathSum(triangle,n);

    return 0;
}