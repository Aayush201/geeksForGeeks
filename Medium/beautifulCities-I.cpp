/*
Problem Link : https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-149/problems
Its Problem C
*/

class Solution
{
public:
    vector<int> canTrade(int n, vector<int> &beautifulness, int q,
                         vector<vector<int>> &queries)
    {
        // Write your code here.
        map<int, int> mp;
        vector<int> pre;
        pre.push_back(0);
        for (auto x : beautifulness)
        {
            mp[x]++;
            pre.push_back(mp[x]);
        }
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int x = queries[i][0];
            int y = queries[i][1];
            int v1 = y - x + 1;
            // cout << pre[x] << " " << pre[y] << endl;
            int v2 = abs(pre[x] - pre[y]) + 1;
            if (v1 == v2 && beautifulness[x - 1] == beautifulness[y - 1])
                ans.push_back(1);
            else
                ans.push_back(0);
        }
        return ans;
    }
};