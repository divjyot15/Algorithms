#include <bits/stdc++.h>

using namespace std;

void path(int di[],int dj[],int i,int j,vector<vector<int>> mat,int n,string s,vector<string> &ans,vector<vector<int>> vis){

    if(i ==n-1 && j == n-1){
        ans.push_back(s);
        return;
    }
    string dir = "DLRU";
    for (int ind = 0; ind < 4; ind++)
    {
        int nexti = i + di[ind];
        int nextj = j + dj[ind];

        if(nexti>=0 && nextj>=0 && nexti<n && nextj<n && vis[nexti][nextj]!=1 && mat[nexti][nextj] ==1){
            vis[i][j] = 1;
            path(di,dj,nexti,nextj,mat,n,s+dir[ind],ans,vis);
            vis[i][j] = 0;
        }

    }
    
    
    
   
}





vector<string> findpath(vector<vector<int>> mat,int n){
    vector<string> ans;
    string s="";
    int di[] ={1,0,0,-1};
    int dj[] ={0,-1,1,0};
    vector<vector<int>> vis(n, vector<int>(n,0));
    int i =0;
    int j=0;
    path(di,dj,i,j,mat,n,s,ans,vis);
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