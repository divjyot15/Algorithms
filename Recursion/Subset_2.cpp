// Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

#include <bits/stdc++.h>

using namespace std;

void printsubsets(int ind, int arr[], int n, vector<int> res,vector<vector<int>> &ans){
    ans.push_back(res);
    for (int i = ind; i < n; i++)
    {
        if (i>ind && arr[i] == arr[i-1])
        {
            continue;
        }
        res.push_back(arr[i]);
        printsubsets(i+1,arr,n,res,ans);
        res.pop_back();
    }
    
}

vector<vector<int>> subsets(int arr[],int n){
    vector<int> res;
    vector<vector<int>> ans;
    sort(arr,arr+n);
    printsubsets(0,arr,n,res,ans);
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    vector<vector<int>> result =  subsets(arr,n);

    for (auto x : result)
    {
        for(int i=0; i<x.size(); i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
    

return 0;
}