#include <bits/stdc++.h>

using namespace std;

//memoization

// int helper(int i, int j, string s1, string s2, vector<vector<int>> &dp){

//     if(i ==0 || j==0){
//         return 0;
//     }

//     if(dp[i][j] !=-1) return dp[i][j];

//     if(s1[i-1] == s2[j-1]){
//         return dp[i][j] = 1 + helper(i-1,j-1,s1,s2,dp);
//     }

//     return dp[i][j] = 0+ max(helper(i-1,j,s1,s2,dp), helper(i,j-1,s1,s2,dp));
// }


int lcs(string s1, string s2){
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1,-1));

    // return helper(n,m,s1,s2,dp); //We are not passing n-1, m-1 because here it is shift of index which will help in tabulation as we cammot have negative indexes there
    // we can also pass n-1,m-1 and then the base case will be i<0 and j<0

    for(int i =0;i<=n; i++){
        dp[i][0] =0;
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] =0;
    }

    for(int i=1;i<=n;i++){
        for(int j =1;j <=m ;j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j]= 0 + max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main()
{
    string s1,s2;
    cout<<"Enter the first String\n";
    getline(cin,s1);
    cout<<"Enter the second String\n";
    getline(cin,s2);
    cout<<"the length is\n";
    cout<<lcs(s1,s2);


return 0;
}