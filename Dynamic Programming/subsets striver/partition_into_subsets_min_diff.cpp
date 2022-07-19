// You are given an array containing N non-negative integers. Your task is to partition this array into two subsets such that the
//  absolute difference between subset sums is minimum.
// You just need to find the minimum absolute difference considering any valid division of the array elements.


// ----------------------------------SOLUTION-----------------------------------------------------


#include<bits/stdc++.h>

using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum =0;
    
    for(int i=0;i<n;i++){
        sum += arr[i];
    }
    
	vector<vector<bool>> dp(n, vector<bool>(sum+1,false));
    

    for(int i =0;i<n;i++){
        dp[i][0] = true;
    }
    
    if(arr[0]<=sum) dp[0][arr[0]]= true;
    

    
    for(int i= 1; i<n;i++){
        for(int target=1; target<=sum; target++){
            
            bool nottake = dp[i-1][target];
            bool take  = false;
            if(arr[i]<=target)
             take = dp[i-1][target - arr[i]];
            
            dp[i][target] = take||nottake;
        }
    }
    

    
    int mini = 1e9;
    
    for(int j = 0; j<=sum; j++){
        if(dp[n-1][j] == true){
        int s1= j;
        int s2 = sum - s1;
        int diff = abs(s1-s2);
        mini = min(diff,mini);
        }    
            
    }
    
    return mini;
    
}


int main() {

  vector<int> arr = {1,2,3,4};
  int n = arr.size();

  cout << "The minimum absolute difference is: " << minSubsetSumDifference(arr, n);

  return 0;
}