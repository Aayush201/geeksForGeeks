/*
Problem Link :  https://www.geeksforgeeks.org/problems/reverse-bits3556/1
*/

class Solution
{
public:
    long long reversedBits(long long x)
    {
        // code here
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans += (1ll << (31 - i)) * (bool)(x & (1ll << i));
        }
        return ans;
    }
};
