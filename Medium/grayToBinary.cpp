/*
Problem Link : https://www.geeksforgeeks.org/problems/gray-to-binary-equivalent-1587115620/1
*/

class Solution
{
public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {

        // Your code here
        int ans = 0, flag = 0, prev = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (!flag && (n & (1 << i)))
            {
                ans = (1 << i);
                prev = 1;
                flag = 1;
            }
            else
            {
                bool val = (prev ^ (bool)(n & (1 << i)));
                ans += val * (1 << i);
                prev = val;
            }
        }
        return ans;
    }
};
