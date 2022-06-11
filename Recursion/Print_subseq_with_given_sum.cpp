#include <bits/stdc++.h>

using namespace std;

void printsub(int ind,vector<int> res, int arr[], int s,int sum ,int n){
    if(ind == n){
        if(s==sum){
            for(int i =0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
        cout<<endl;
        }
        return;
    }

    res.push_back(arr[ind]);
    s= s+arr[ind];
    printsub(ind+1,res,arr,s,sum,n);
    res.pop_back();
    s= s- arr[ind];
    printsub(ind+1,res,arr,s,sum,n);


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
    printsub(0,res,arr,0,sum,n);
return 0;
}