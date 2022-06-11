#include <bits/stdc++.h>

using namespace std;

void path(int i,int j,vector<vector<int>> mat,int n,string s,vector<string> &ans,vector<vector<int>> vis){
    if(i ==n-1 && j == n-1){
        ans.push_back(s);
        return;
    }
    // FOR DOWN
    
    if(i+1< n &&  mat[i+1][j] == 1 && vis[i+1][j]!=1){
        vis[i][j] =1;
        path(i+1,j,mat,n,s+"D",ans,vis);
        vis[i][j] =0;
    }
    // FOR LEFT
    if(j-1>=0 && mat[i][j-1] ==1 && vis[i][j-1] != 1){
        vis[i][j] =1;
        path(i,j-1,mat,n,s+"L",ans,vis);
        vis[i][j] =0;
    }

    // FOR RIGHT
    if(j+1>=0 && mat[i][j+1] ==1 && vis[i][j+1] != 1){
        vis[i][j] =1;
        path(i,j+1,mat,n,s+"R",ans,vis);
        vis[i][j] =0;
    }
    
    // FOR UP
    if(i-1>= 0 &&  mat[i-1][j] == 1 && vis[i-1][j]!=1){
        vis[i][j] =1;
        path(i-1,j,mat,n,s+"U",ans,vis);
        vis[i][j] =0;
    }
}


vector<string> findpath(vector<vector<int>> mat,int n){
    vector<string> ans;
    string s="";
    vector<vector<int>> vis(n, vector<int>(n,0));
    int i =0;
    int j=0;
    path(i,j,mat,n,s,ans,vis);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<int>> mat;
    for (int i = 0; i < n; i++)
    {
        vector<int> a;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin>>temp;
            a.push_back(temp);
        }
        mat.push_back(a);
    }

    vector<string> result = findpath(mat,n);

    for (auto x : result)
    {
        cout<<x;
        cout<<endl;
    }

    
    
return 0;
}