/*
Problem Link : https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-149/problems
Its Problem A
*/

class Solution
{
public:
    vector<int> prefixDistinct(int n, vector<int> &arr)
    {
        // Write your code here.
        vector<int> ans;
        map<int, int> mp;
        for (auto x : arr)
        {
            mp[x]++;
            ans.push_back(mp.size());
        }
        return ans;
    }
};