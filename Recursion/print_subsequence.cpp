#include <bits/stdc++.h>

using namespace std;

void sub(int ind,int arr[],int n, vector<int> res){
    if(ind == n){
        for(int i =0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
        return;
    }
    res.push_back(arr[ind]);
    sub(ind+1,arr,n,res);
    res.pop_back();
    sub(ind+1,arr,n,res);
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

    vector<int> res;

    sub(0,arr,n,res);
    
return 0;
}