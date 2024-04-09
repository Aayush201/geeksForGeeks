/*
Problem Link : https://www.geeksforgeeks.org/problems/alone-in-couple5507/1
*/

class Solution
{
public:
    int findSingle(int n, int arr[])
    {
        // code here
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= arr[i];
        return ans;
    }
};