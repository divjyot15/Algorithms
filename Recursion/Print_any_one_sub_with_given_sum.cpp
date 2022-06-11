#include <bits/stdc++.h>

using namespace std;

bool printsub(int ind,vector<int> res, int arr[], int s,int sum ,int n){
    if(ind == n){
        if(s==sum){
            for(int i =0;i<res.size();i++){
                cout<<res[i]<<" ";
            }
        cout<<endl;
        return true;
        }
        else return false;
    }

    res.push_back(arr[ind]);
    s= s+arr[ind];
    if(printsub(ind+1,res,arr,s,sum,n)== true) return true;;
    res.pop_back();
    s= s- arr[ind];
    if(printsub(ind+1,res,arr,s,sum,n) == true) return true;

    return false;

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