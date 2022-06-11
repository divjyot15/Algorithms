#include <bits/stdc++.h>

using namespace std;

int printsub(int ind,vector<int> res, int arr[], int s,int sum ,int n){
    if(ind == n){
        if(s==sum){
            for(int i =0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
        cout<<endl;
        return 1;
        }
        else return 0;
    }

    res.push_back(arr[ind]);
    s= s+arr[ind];
    int l = printsub(ind+1,res,arr,s,sum,n);
    res.pop_back();
    s= s- arr[ind];
    int r = printsub(ind+1,res,arr,s,sum,n);
    return l+r;

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
    int sum;
    cin>>sum;

    vector<int> res;
    int total = printsub(0,res,arr,0,sum,n);
    cout<<total;
return 0;
}