/*
Problem Link : https://www.geeksforgeeks.org/problems/number-of-ways2552/0
*/
class Solution
{
public:
    long long int solve(int row, vector<long long> &dp)
    {
        if (row == 0)
            return 1;
        if (row < 0)
            return 0;
        if (dp[row] != -1)
            return dp[row];
        return dp[row] = solve(row - 1, dp) + solve(row - 4, dp);
    }
    long long int arrangeTiles(int N)
    {
        // code here
        vector<long long> dp(N + 1, -1);
        return solve(N, dp);
    }
};
