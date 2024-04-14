/*
Problem Link : https://www.geeksforgeeks.org/problems/count-the-elements1529/1
*/

class Solution
{
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q)
    {
        // Your code goes here;
        int m = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            m = max({m, a[i], b[i]});
        }
        vector<int> ans(m + 1, 0);
        for (int i = 0; i < n; i++)
        {
            ans[b[i]]++;
        }
        for (int i = 1; i <= m; i++)
        {
            ans[i] += ans[i - 1];
        }
        vector<int> res;
        for (auto x : query)
        {
            res.push_back(ans[a[x]]);
        }
        return res;
    }
};