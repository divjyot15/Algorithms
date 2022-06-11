// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

// Each number in candidates may only be used once in the combination.

// Note: The solution set must not contain duplicate combinations.

// Should be printed in sorted order

#include <bits/stdc++.h>

using namespace std;

void combsum(int ind,int n, int target, int arr[],vector<int> res, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(res);
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if(i>ind && arr[i] == arr[i-1]){
            continue;
        }
        if(arr[i]> target){
            break;
        }
        res.push_back(arr[i]);
        combsum(i+1,n,target-arr[i],arr,res,ans);
        res.pop_back();
    }
    
}

vector<vector<int>> combinations(int arr[],int target, int n){
    sort(arr,arr+n);
    
    vector<int> res;
    vector<vector<int>> ans;
    combsum(0,n, target,arr,res,ans);
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

    int target;
    cin>>target;



    vector<vector<int>> result =  combinations(arr,target,n);

    for (auto x : result)
    {
        for(int i=0; i<x.size(); i++){
            cout<<x[i]<<" ";
        }
        cout<<endl;
    }
return 0;
}