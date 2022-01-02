#include <bits/stdc++.h>

using namespace std;

int CountSubsets(int set[],int sum, int n)
{
    if (sum==0)
    {
        return 1;
    }
    else if (n==0 && sum!=0)
    {
        return 0;
    }
    else if (set[n-1]>sum)
    {
        return CountSubsets(set,sum,n-1);
    }
    else
    {
        return CountSubsets(set,sum,n-1)+CountSubsets(set,sum-set[n-1],n-1);
    }
    
}

int main()
{
    int n;
    cout << "Enter the number of elements in the set" << endl;
    cin >> n;
    cout << "Enter the set" << endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }
    int sum;
    cout << "Enter the sum" << endl;
    cin >> sum;

    cout<<"Number of subsets with given sum is :"<<CountSubsets(set,sum,n);
    

    return 0;
}