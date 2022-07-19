
#include<bits/stdc++.h>

using namespace std;


// int helper(int ind, int target, vector<int> &num, int n,vector<vector<int>> &dp){
// //     cout<<"index is "<<ind<<endl;
// //     if(sum> target){
// //         return 0;
// //     }
//     if(ind == n){
//         if(target == 0){
// //             cout<<"found"<<endl;
//             return 1;
//         }
//         else return 0;
//     }
    
//     if(dp[ind][target] != -1) return dp[ind][target];
    
//     int take =0;
//     if(num[ind] <= target)
//         take = helper(ind+1,target - num[ind], num, n,dp);
    
//     int nottake = helper(ind+1,target,num,n,dp);

    
// //     cout<<take + nottake<<endl;
    
//     return dp[ind][target] = take+nottake;
// }

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(tar+1,-1));
//     return helper(0, tar, num, n,dp);
    
    vector<vector<int>> dp(n, vector<int>(tar+1,0));
    
    for(int i = 0; i<n; i++){
        dp[i][0] =1;
    }
    
    if(num[n-1] <= tar)
    dp[n-1][num[n-1]] = 1;
 
    for(int i=n-2;i>=0;i--){
        for(int j =tar; j>=0;j--){
            int take =0;
            if(num[i] <= j)
                take = dp[i+1][j - num[i]];
    
             int nottake = dp[i+1][j];
            
            dp[i][j] = take+nottake;
        }
    }
    
    return dp[0][tar];
}

int main() {

    vector<int> arr = {1,2,2,3};
    int tar = 3;
                                 
  cout<<"The number of subsets are " <<findWays(arr,tar);
}