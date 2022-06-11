#include <bits/stdc++.h>

using namespace std;

void ss(int ind, int n, int arr[],int sum,vector<int> &res){
    if(ind == n){
        res.push_back(sum);
        return;
    }
    ss(ind+1,n,arr,sum + arr[ind], res);
    ss(ind+1,n,arr,sum,res);
}

vector<int> subsetsum(int arr[], int n){
    vector<int> res;
    ss(0,n,arr,0,res);
    sort(res.begin(),res.end());
    return res;
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

    vector<int> result =  subsetsum(arr,n);

    for (auto x : result)
    {
        cout<<x<<" ";
    }
        cout<<endl;
    
return 0;
}