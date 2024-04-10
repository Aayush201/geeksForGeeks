/*
Problem Link : https://www.geeksforgeeks.org/problems/subsets-with-xor-value2023/0
*/

class Solution
{
public:
    int solve(int val, int index, int k, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (index == 0)
            return val == k;
        if (dp[index][val] != -1)
            return dp[index][val];
        int pick = solve(val ^ arr[index - 1], index - 1, k, arr, dp);
        int notPick = solve(val, index - 1, k, arr, dp);
        return dp[index][val] = pick + notPick;
    }
    int subsetXOR(vector<int> arr, int N, int K)
    {
        // code here
        vector<vector<int>> dp(N + 1, vector<int>(10001, -1));
        return solve(0, N, K, arr, dp);
    }
};