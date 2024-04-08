/*
Problem Link : https://www.geeksforgeeks.org/problems/optimal-strategy-for-a-game-1587115620/1
*/
/*
    Pepcoding video for intuition : https://www.youtube.com/watch?v=ww4V7vRIzSk
*/
class Solution
{
public:
    long long solve(int leftIndex, int rightIndex, int *arr, vector<vector<long long>> &dp)
    {
        if (leftIndex > rightIndex)
            return 0;
        if (dp[leftIndex][rightIndex] != -1)
            return dp[leftIndex][rightIndex];
        long long v1 = 0, v2 = 0;
        v1 = arr[leftIndex] +
             min(solve(leftIndex + 2, rightIndex, arr, dp), solve(leftIndex + 1, rightIndex - 1, arr, dp));

        v2 = arr[rightIndex] +
             min(solve(leftIndex + 1, rightIndex - 1, arr, dp), solve(leftIndex, rightIndex - 2, arr, dp));

        return dp[leftIndex][rightIndex] = max(v1, v2);
    }
    long long maximumAmount(int n, int arr[])
    {
        // Your code here
        vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, -1));
        return solve(0, n - 1, arr, dp);
    }
};
