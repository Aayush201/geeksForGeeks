/*
Problem Link : https://www.geeksforgeeks.org/problems/count-pairs-in-an-array4145/1
*/

class Solution
{
public:
    void findPairsUtil(int *arr, int start, int mid, int end, int &ans)
    {
        vector<int> tmp;
        int low = start;
        int high = mid + 1;
        while (low <= mid && high <= end)
        {
            if (arr[low] <= arr[high])
            {
                tmp.push_back(arr[low]);
                low++;
            }
            else
            {
                ans += mid - low + 1;
                tmp.push_back(arr[high]);
                high++;
            }
        }
        while (low <= mid)
        {
            tmp.push_back(arr[low++]);
        }
        while (high <= end)
        {
            tmp.push_back(arr[high++]);
        }
        for (int i = 0; i < tmp.size(); i++)
        {
            arr[i + start] = tmp[i];
        }
    }
    void findPairs(int *arr, int start, int end, int &ans)
    {
        if (start >= end)
            return;
        int mid = start + (end - start) / 2;
        findPairs(arr, start, mid, ans);
        findPairs(arr, mid + 1, end, ans);
        findPairsUtil(arr, start, mid, end, ans);
    }
    int countPairs(int arr[], int n)
    {
        // Your code goes here
        int ans = 0;
        for (int i = 0; i < n; i++)
            arr[i] = i * arr[i];
        findPairs(arr, 0, n - 1, ans);
        return ans;
    }
};