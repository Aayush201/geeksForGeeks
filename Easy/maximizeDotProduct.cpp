/*
Problem Link : https://www.geeksforgeeks.org/problems/maximize-dot-product2649/1
*/

class Solution
{
public:
    int solve(int n, int m, int *a, int *b, vector<vector<int>> &dp)
    {
        if (n == 0 || m == 0)
            return 0;
        if (dp[n][m] != -1)
            return dp[n][m];
        // This is the crux of the question
        if (n == m)
        {
            int val = 0;
            for (int i = 0; i < n; i++)
            {
                val += a[i] * b[i];
            }
            return dp[n][m] = val;
        }
        int v1 = a[n - 1] * b[m - 1] + solve(n - 1, m - 1, a, b, dp);
        int v2 = solve(n - 1, m, a, b, dp);
        dp[n][m] = max(v1, v2);
    }
    int maxDotProduct(int n, int m, int a[], int b[])
    {
        // Your code goes here
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return solve(n, m, a, b, dp);
    }
};
