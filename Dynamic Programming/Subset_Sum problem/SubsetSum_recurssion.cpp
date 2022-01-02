#include <bits/stdc++.h>

using namespace std;

bool subset(int set[],int sum, int n){

    if (sum == 0)
    {
        return true;
    }
    else if (n==0 && sum!=0)
    {
        return false;
    }
    else if (set[n-1]>sum)
    {
        return subset(set,sum,n-1);
    }
    else 
    {
        return subset(set,sum-set[n-1],n-1)||subset(set,sum,n-1);
    }

    
    
}

int main()
{   
    int n;
    cout<<"Enter the elements in the set"<<endl;
    cin>>n;
    cout<<"Enter the set"<<endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin>>set[i];
    }
    int sum;
    cout<<"Enter the sum"<<endl;
    cin>>sum;

    if (subset(set,sum,n)==true)
    {
        cout<<"There is a subset with given sum"<<endl;
    }
    else
    {
        cout<<"No subset with given sum"<<endl;
    }
    



return 0;
}