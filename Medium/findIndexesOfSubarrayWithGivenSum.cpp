/*
Problem Link : https://www.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1?page=1&difficulty=Medium&status=unsolved&sortBy=submissions
*/

class Solution
{
public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s)
    {
        // Your code here
        vector<int> ans;
        long long sum = 0, j = 0, i = 0;
        while (j < n)
        {
            sum += arr[j];
            while (i <= j && sum > s)
            {
                sum -= arr[i];
                i++;
            }
            if (sum == s && s)
            {
                return {i + 1, j + 1};
            }
            else if (s == 0)
            {
                if (!arr[j])
                    return {j + 1, j + 1};
            }
            j++;
        }
        return {-1};
    }
};