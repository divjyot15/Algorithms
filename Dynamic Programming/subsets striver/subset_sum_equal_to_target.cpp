#include<bits/stdc++.h>

using namespace std;

// bool helper(int ind,int n, int target,vector<int> &arr,vector<vector<int>> &dp){
   
//     if(target ==0) return true;
//     if(ind==n-1) return (arr[ind] == target);
//     if(dp[ind][target]!= -1) return dp[ind][target];
//     bool nottake = helper(ind+1, n, target,arr,dp);
//     bool take = false;
//     if(arr[ind]<=target){
//         take = helper(ind+1, n, target - arr[ind], arr,dp);
//     }
    
//     return dp[ind][target] = take||nottake;
// }

bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<int>> dp(n, vector<int>(k+1,-1));
//     return helper(0,n,k,arr,dp);

    
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=k)
        dp[0][arr[0]] = true;
    
    for(int ind = 1; ind<n; ind++){
        for(int target= 1; target<=k; target++){
            
            bool notTaken = dp[ind-1][target];
    
            bool taken = false;
                if(arr[ind]<=target)
                    taken = dp[ind-1][target-arr[ind]];
        
            dp[ind][target]= notTaken||taken;
        }
    }
    
    return dp[n-1][k];
    
   
        
}

int main(){

    int n,k;
    cin>>n>>k;

    vector<int> arr;

    int temp;
    for(int i =0;i<n;i++){
        cin>>temp;
        arr.push_back(temp);
    }

    cout<<subsetSumToK(n,k, arr);

    return 0;
}