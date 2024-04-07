/*
Problem Link : https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-149/problems
Its Problem B
*/

class Solution
{
public:
    int minJumps(int n, vector<int> &arr)
    {
        // Code Here
        map<int, int> mp;
        int maxJump = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            if (!mp[arr[i]])
                mp[arr[i]] = i;
            else
            {
                maxJump = max(maxJump, mp[arr[i]] - i);
            }
        }
        // cout << maxJump << endl;
        int ans = n - maxJump;
        if (n == 1)
            ans = 0;
        return ans;
    }
};