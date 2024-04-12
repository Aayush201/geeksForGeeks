/*
Problem Link : https://www.geeksforgeeks.org/problems/sum-of-products5049/1#
*/

class Solution
{
public:
    long long pairAndSum(int n, long long arr[])
    {
        // code here
        long long ans = 0;
        vector<int> counts(32, 0);
        for (int i = 31; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                counts[31 - i] += (bool)(arr[j] & (1ll << i));
            }
        }
        for (int j = 0; j < n; j++)
        {
            for (int i = 31; i >= 0; i--)
            {
                bool Set = (bool)(arr[j] & (1ll << i));
                if (Set)
                {
                    counts[31 - i]--;
                    if (counts[31 - i] > 0)
                    {
                        ans += 1ll * (counts[31 - i]) * (1ll << i);
                    }
                }
            }
        }
        return ans;
    }
};