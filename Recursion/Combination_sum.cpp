#include <bits/stdc++.h>

using namespace std;



void comsum(int ind,int arr[],vector<int> res,int target,int n,vector<vector<int>> &ans){
    if(ind == n){
        if( target == 0){
            ans.push_back(res);
        }
        return;
    }
    if(arr[ind]<=target){
        res.push_back(arr[ind]);
        comsum(ind,arr,res,target - arr[ind],n,ans);
        res.pop_back();
    }
    comsum(ind+1,arr,res,target,n,ans);



}

vector<vector<int>> combinations(int arr[],int target,int n){

    vector<int> res;
    vector<vector<int>> ans;
    comsum(0,arr,res,target,n,ans);
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