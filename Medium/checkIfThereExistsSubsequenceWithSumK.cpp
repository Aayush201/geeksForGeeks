/*
Problem Link : https://www.geeksforgeeks.org/problems/check-if-there-exists-a-subsequence-with-sum-k/0
*/

class Solution
{
public:
    int solve(int index, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (index == 0)
            return k == 0;
        if (k < 0)
            return 0;
        if (k == 0)
            return 1;
        if (dp[index][k] != -1)
            return dp[index][k];
        int pick = solve(index - 1, k - arr[index - 1], arr, dp);
        int notPick = solve(index - 1, k, arr, dp);
        return dp[index][k] = pick || notPick;
    }
    bool checkSubsequenceSum(int n, vector<int> &arr, int k)
    {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return solve(n, k, arr, dp);
    }
};