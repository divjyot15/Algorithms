#include<bits/stdc++.h>

using namespace std;


// int helper(int ind,int target, int n,vector<int> &arr,vector<vector<int>> &dp){
//     if(target == 0){
//         return true;
//     }
//     if(ind ==0) return (arr[ind] == target);
//     if(dp[ind][target]!= -1) return dp[ind][target];
//     bool nottake = helper(ind-1,target,n,arr,dp);
//     bool take = false;
//     if(arr[ind] <= target)
//      take = helper(ind-1,target-arr[ind],n,arr,dp);
    
//     return dp[ind][target] = take||nottake;
    
// }

bool canPartition(vector<int> &arr, int n)
{
    
    int sum = 0;
    for (int i =0 ;i<n;i++){
        sum+= arr[i];
    }
    
    
    
    if(sum%2!=0){
        return false;
    }
    else{
//         vector<vector<int>> dp(n, vector<int>(sum/2+1,-1));
//         return helper(n-1,sum/2,n,arr,dp);    
        
        vector<vector<bool>> dp(n, vector<bool>(sum/2+1,false));
//             int dp[n][sum/2+1];
        
        for(int i = 0;i<n;i++) dp[i][0] = true;
        
        if(arr[0]<=sum/2)
        dp[0][arr[0]] == true;
        
        for(int i= 1;i<n;i++){
            for(int target = 1; target<=sum/2; target++){
                
                bool nottake = dp[i-1][target];
                bool take = false;
                if(arr[i] <= target)
                     take = dp[i-1][target- arr[i]];
                
                dp[i][target] = take||nottake;
            }   
        }
        
       return dp[n-1][sum/2]; 
        
    }
}

int main()
{


  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(arr,n))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";


return 0; 
}