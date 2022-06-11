#include <bits/stdc++.h>

using namespace std;

int mcm(int arr[],int L,int R){
    if (L>=R)
    {
        return 0;
    }
    int res = INT_MAX;
    int temp;
    for (int i = L; i < R; i++)
    {
        int temp = mcm(arr,L,i)+ mcm(arr,i+1,R) + (arr[L-1]*arr[i]*arr[R]);
        
        res = min(res,temp);
    }
    return res;
            
}

int main()
{
    int n ;
    cout<<"Number of matrices"<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"Enter the dimensions array"<<endl;
    for (int i = 0; i < n+1; i++)
    {
        cin>>arr[i];
    }
    int L = 1;
    int R = n;

    cout<<"Minimum number of operations are: "<<mcm(arr,L,R);

return 0;
}