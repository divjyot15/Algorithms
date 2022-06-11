#include <bits/stdc++.h>

using namespace std;

void perm(int ind, vector<int> arr, vector<vector<int>> &ans,int n){
    if(ind == n){
        ans.push_back(arr);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        swap(arr[ind],arr[i]);
        perm(ind+1,arr,ans,n);
        swap(arr[ind],arr[i]);
    }
    
}

vector<vector<int>> permutations(vector<int> arr, int n){
    vector<vector<int>> ans;
    perm(0,arr,ans,n);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin>>temp;
        arr.push_back(temp);
    }

    vector<vector<int>> result =  permutations(arr,n);

    for (auto x : result)
    {
        for(int i=0; i<x.size(); i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}