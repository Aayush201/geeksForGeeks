/*
Problem Link : https://www.geeksforgeeks.org/problems/minimum-points-to-reach-destination0540/1
*/

class Solution
{
public:
    int solve(vector<vector<int>> &points, int i, int j, int m, int n, vector<vector<int>> &dp)
    {
        if (i >= m || j >= n)
            return INT_MAX;
        if (i == m - 1 && j == n - 1)
            return points[i][j];
        if (dp[i][j] != INT_MIN)
            return dp[i][j];
        int down = points[i][j] + solve(points, i + 1, j, m, n, dp);
        int right = points[i][j] + solve(points, i, j + 1, m, n, dp);
        down = min(down, 0);
        right = min(right, 0);
        return dp[i][j] = max(down, right);
    }
    int minPoints(int m, int n, vector<vector<int>> points)
    {
        vector<vector<int>> dp(m, vector<int>(n, INT_MIN));
        int val = solve(points, 0, 0, m, n, dp);
        return abs(val) + 1;
    }
};