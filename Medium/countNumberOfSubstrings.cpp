/*
Problem Link : https://www.geeksforgeeks.org/problems/count-number-of-substrings4528/1?page=1&category=two-pointer-algorithm,sliding-window&difficulty=Medium&status=unsolved&sortBy=submissions
*/

class Solution
{
public:
    long long int solve(string &s, int k)
    {
        long long int ans = 0, i = 0, j = 0, n = s.length(), count = 0;
        vector<int> mp(26);
        while (j < n)
        {
            if (mp[s[j] - 'a'] == 0)
                count++;
            mp[s[j] - 'a']++;
            while (i <= j && count > k)
            {
                mp[s[i] - 'a']--;
                if (!mp[s[i] - 'a'])
                    count--;
                i++;
            }
            ans += j - i + 1;
            j++;
        }
        return ans;
    }
    long long int substrCount(string s, int k)
    {
        // code here.
        return 1ll * solve(s, k) - 1ll * solve(s, k - 1);
    }
};
