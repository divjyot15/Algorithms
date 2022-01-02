#include <bits/stdc++.h>

using namespace std;

bool subsetSum(int set[], int sum, int n)
{
    int dp[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {

            if (j == 0)
            {
                dp[i][j] = true;
            }

            else if (i == 0 && j != 0)
            {
                dp[i][j] =false;
            }

            else if (set[n - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }

            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    return dp[n][sum];
}

bool check_partition(int set[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += set[i];
    }

    cout<<"sum is: "<<sum<<endl;

    if (sum % 2 != 0)
    {
        return false;
    }
    else
    {
        return subsetSum(set, sum/2, n);
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

    if (check_partition(set, n) == true)
    {
        cout << "Partitioning the set into equal subset is possible" << endl;
    }
    else
    {
        cout << "Not Possible" << endl;
    }

    return 0;
}