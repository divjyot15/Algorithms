#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mem;

bool subsetSum(int set[], int sum, int n)
{
    if (sum==0)
    {
        return true;
    }
    else if (n==0 && sum!=0)
    {
        return false;
    }
    else if (mem[sum][n]!=-1)
    {
        return mem[sum][n];
    }
    else if (set[n-1]>sum)
    {
        mem[sum][n]= subsetSum(set,sum,n-1);
    }
    else
    {
      mem[sum][n]= subsetSum(set,sum,n-1)||subsetSum(set,sum-set[n-1],n-1);  
    }
    
    return mem[sum][n];
    

}

bool check_partition(int set[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += set[i];
    }

    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i <= sum/2; i++)
        {
            for (int j = 0; i <= n; j++)
            {
                mem[i][j]= -1;
            }
            
        }
        return subsetSum(set,sum/2,n);
    }
}

int main()
{
    int n;
    cout << "Enter the elements in the set" << endl;
    cin >> n;
    cout << "Enter the set" << endl;
    int set[n];
    for (int i = 0; i < n; i++)
    {
        cin >> set[i];
    }


    if (check_partition(set,n) == true)
    {
        cout << "Partitionin the set into equal subset is possible" << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}