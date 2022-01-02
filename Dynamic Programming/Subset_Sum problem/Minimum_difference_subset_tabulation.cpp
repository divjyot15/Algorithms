#include <bits/stdc++.h>

using namespace std;

int minimum_diff(int set[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + set[i];
    }

    bool dp[n + 1][sum / 2 + 1];

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= sum / 2; j++)
        {
            if (j == 0)
            {
                dp[i][j] == true;
            }
            else if (i == 0 && j != 0)
            {
                dp[i][j] == false;
            }

            else if (set[i - 1] > j)
            {
                dp[i][j] = dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
            }
        }
    }

    int minimum = INT16_MAX;
    int S1;
    int S2;

    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[n][i] == true)
        {
            S1 = i;
            S2 = sum - S1;
            int diff = abs(S2 - S1);
            if (diff<minimum)
            {
                minimum =diff;
            }
            
        }
    }
    return minimum;
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

    cout<<"The Minimum Sum difference is: "<<minimum_diff(set,n);

    return 0;
}